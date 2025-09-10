#include "./Cvector.h"

#include <stdlib.h>

/*
struct Cvector {
    size_t size_;
    size_t capacity_;
    size_t data_size_; 
    void* data_;
};
*/

/* ------------- private functions ------------- */
static void swap(struct Cvector *vec, void *a, void *b) {
    for (int i = 0; i < vec->data_size_; ++i) {
        uint8_t temp = *((uint8_t *)a + i);
        *((uint8_t *)a + i) = *((uint8_t *)b + i);
        *((uint8_t *)b + i) = temp;
    }
}

static void fill_zero(struct Cvector *vec, void *where) {
    for (uint8_t i = 0; i < vec->data_size_; ++i) {
        *((uint8_t *)where + i) = 0;
    }
}

static void realloc_vec(struct Cvector *vec) {
    vec->capacity_ *= 2;
    void *new_data = malloc(vec->capacity_ * vec->data_size_);
    
    for (size_t el = 0; el < vec->size_; ++el) {
        for (uint8_t byte = el; byte < vec->data_size_; ++byte) {
            *((uint8_t *)new_data + byte) = *((uint8_t *)vec->data_ + byte);
        }
    }

    free(vec->data_);
    vec->data_ = new_data;
}
/* --------------------------------------------- */


/* ------------------------ public functions ------------------------ */
/* constructor */
void init_vec(struct Cvector *vec, size_t size, size_t data_size) {
    vec->size_ = 0;
    vec->capacity_ = size * 2;
    vec->data_size_ = data_size;
    vec->data_ = malloc(vec->capacity_ * vec->data_size_);
}

void destruct_vec(struct Cvector *vec) {
    vec->size_ = 0;
    vec->capacity_ = 0;
    vec->data_size_ = 0;
    free(vec->data_);
    vec->data_ = 0x0;
}

/* capacity */
uint8_t empty(struct Cvector *vec) {
    return (vec->size_ != 0) ? 0 : 1;
}

size_t get_size(struct Cvector *vec) {
    return vec->size_;
}

size_t get_capacity(struct Cvector *vec) {
    return vec->capacity_;
}

/* element access */
void *at_vec(struct Cvector *vec, size_t pos) {
    if (0 > pos && pos > vec->size_) {
        exit(1);
    }
    return vec->data_ + (vec->data_size_ * pos);
}

void *front_vec(struct Cvector *vec) {
    return vec->data_;
}

void *back_vec(struct Cvector *vec) {
    return vec->data_ + ((vec->size_-1) * vec->data_size_);
}

/* modifiers */
void *insert_vec(struct Cvector *vec, size_t pos) {
    if (0 > pos && pos > vec->size_) {
        exit(1);
    }

    if (vec->size_+1 > vec->capacity_) {
        realloc_vec(vec);
    }

    void *last = (uint8_t *)vec->data_ + (vec->size_ * vec->data_size_); 
    ++vec->size_;
    fill_zero(vec, last);
   
    void *where = (uint8_t *)vec->data_ + (pos * vec->data_size_);
    
    for (uint8_t *i = last; (void *)i > where; i -= vec->data_size_) {
        swap(vec, (void *)(i - vec->data_size_), (void *)i);
    }

    return where;
}

void erase_vec(struct Cvector *vec, size_t pos) {
    if (0 > pos && pos > vec->size_) {
        exit(1);
    }

    void *where = vec->data_ + (pos * vec->data_size_);
    fill_zero(vec, where);

    void *last = (uint8_t *)vec->data_ + (vec->size_ * vec->data_size_); 
    for (uint8_t *i = where; (void *)i <= last; i += vec->data_size_) {
        swap(vec, (void *)(i), (void *)(i + vec->data_size_));
    }
    --vec->size_;
}

void *push_vec(struct Cvector *vec) {
    if (vec->size_+1 > vec->capacity_) {
        realloc_vec(vec);
    }

    void *where = (uint8_t *)vec->data_ + (vec->size_ * vec->data_size_); 
    ++vec->size_;

    return where;
}

void pop_vec(struct Cvector *vec) {
    if (vec->size_ == 0) {
        return;
    }
    
    fill_zero(vec, &vec->size_);
    --vec->size_;
}
/* ------------------------------------------------------------------ */
