#include "../include/Cvector.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cvector {
    size_t size_;
    size_t capacity_;
    size_t data_size_; 
    void* data_;
};

/* ------------- private functions ------------- */
static void vec_error(const char *error) {
    fprintf(stderr, "%s\n", error);
}

static void vec_resize(Cvector *vec) {
    vec->capacity_ *= 2;
    vec->data_ = realloc(vec->data_, vec->capacity_ * vec->data_size_);
    if (vec->data_ == NULL) {
        vec_error("error: bad alloc in realloc_vec");
        exit(1);
    }
}

static void set_zero(Cvector *vec, void *where) {
    memset(where, 0, vec->data_size_);
}
/* --------------------------------------------- */


/* ------------------------ public functions ------------------------ */
/* constructor */
Cvector *vec_dinit(size_t size, size_t data_size) {
    Cvector *vec = (Cvector *)malloc(sizeof(Cvector));
    if (vec == NULL) {
        vec_error("error: bad alloc in dinit_vec");
        return NULL;
    }

    vec->size_ = 0;
    vec->capacity_ = (size != 0) ? size * 2 : 10;
    vec->data_size_ = data_size;
    vec->data_ = malloc(vec->capacity_ * vec->data_size_);

    return vec;
}

void vec_destruct(Cvector **vec) {
    free((*vec)->data_);
    free(*vec);
    vec = NULL;
}

/* capacity */
uint8_t vec_empty(Cvector *vec) {
    return (vec->size_ != 0) ? 0 : 1;
}

size_t vec_size(Cvector *vec) {
    return vec->size_;
}

size_t vec_capacity(Cvector *vec) {
    return vec->capacity_;
}

size_t vec_datasize(Cvector *vec) {
    return vec->data_size_;
}

/* element access */
void *vec_at(Cvector *vec, size_t pos) {
    if (0 > pos && pos > vec->size_) {
        vec_error("error: out of range");
        return NULL;
    }
    return vec->data_ + (vec->data_size_ * pos);
}

void *vec_front(Cvector *vec) {
    return vec->data_;
}

void *vec_back(Cvector *vec) {
    return vec->data_ + ((vec->size_-1) * vec->data_size_);
}

void *vec_data(Cvector *vec) {
    return vec->data_;
}

/* modifiers */
void *vec_insert(Cvector *vec, size_t pos) {
    if (vec == NULL) {
        return NULL;
    }

    if (pos < 0 && pos > vec->size_) {
        return NULL;
    }

    if (vec->size_ >= vec->capacity_) {
        vec_resize(vec);
    }

    void *where = (uint8_t *)vec->data_ + (pos * vec->data_size_);
    memmove(where + vec->data_size_, where, vec->data_size_ * (vec->size_ - pos));

    ++vec->size_;
    set_zero(vec, where);

    return where;
}

void vec_erase(Cvector *vec, size_t pos) {
    if (vec == NULL) {
        return;
    }

    if (pos < 0 && pos > vec->size_) {
        return;
    }

    void *where = vec->data_ + (pos * vec->data_size_);
    memmove(where, where + vec->data_size_, vec->data_size_ * (vec->size_ - pos));

    --vec->size_;
    void *last = (uint8_t *)vec->data_ + (vec->size_ * vec->data_size_); 
    set_zero(vec, last);
}

void *vec_push(Cvector *vec) {
    if (vec == NULL) {
        return NULL;
    }

    if (vec->size_ >= vec->capacity_) {
        vec_resize(vec);
    }

    void *where = (uint8_t *)vec->data_ + (vec->size_ * vec->data_size_); 
    ++vec->size_;

    return where;
}

void vec_pop(Cvector *vec) {
    if (vec == NULL) {
        return;
    }

    if (vec->size_ == 0) {
        return;
    }
    
    set_zero(vec, &vec->size_ - vec->data_size_);
    --vec->size_;
}
/* ------------------------------------------------------------------ */
