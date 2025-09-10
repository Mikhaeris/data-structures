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
static void error_vec(const char *error) {
    fprintf(stderr, "%s\n", error);
}

static void resize_vec(Cvector *vec) {
    vec->capacity_ *= 2;
    vec->data_ = realloc(vec->data_, vec->size_ * vec->capacity_);
    if (vec->data_ == NULL) {
        error_vec("error: bad alloc in realloc_vec");
    }
}

static void set_zero(Cvector *vec, void *where) {
    memset(where, 0, vec->data_size_);
}
/* --------------------------------------------- */


/* ------------------------ public functions ------------------------ */
/* constructor */
Cvector *dinit_vec(size_t size, size_t data_size) {
    Cvector *vec = (Cvector *)malloc(sizeof(Cvector));
    if (vec == NULL) {
        error_vec("error: bad alloc in dinit_vec");
    }

    vec->size_ = 0;
    vec->capacity_ = size * 2;
    vec->data_size_ = data_size;
    vec->data_ = malloc(vec->capacity_ * vec->data_size_);

    return vec;
}

Cvector *cinit_vec(Cvector *other) {
    Cvector *vec = (Cvector *)malloc(sizeof(Cvector));
    if (vec == NULL) {
        error_vec("error: bad alloc in dinit_vec");
    }

    vec->size_ = other->size_;
    vec->capacity_ = other->capacity_;
    vec->data_size_ = other->data_size_;
    vec->data_ = malloc(vec->capacity_ * vec->data_size_);
    memcpy(vec->data_, other->data_, vec->data_size_ * (vec->capacity_));

    return vec;
}

void destruct_vec(Cvector *vec) {
    vec->size_ = 0;
    vec->capacity_ = 0;
    vec->data_size_ = 0;
    free(vec->data_);
    vec->data_ = NULL;
    free(vec);
}

/* capacity */
uint8_t empty(Cvector *vec) {
    return (vec->size_ != 0) ? 0 : 1;
}

size_t get_size(Cvector *vec) {
    return vec->size_;
}

size_t get_capacity(Cvector *vec) {
    return vec->capacity_;
}

size_t get_data_size(Cvector *vec) {
    return vec->data_size_;
}

/* element access */
void *at_vec(Cvector *vec, size_t pos) {
    if (0 > pos && pos > vec->size_) {
        return NULL;
    }
    return vec->data_ + (vec->data_size_ * pos);
}

void *front_vec(Cvector *vec) {
    return vec->data_;
}

void *back_vec(Cvector *vec) {
    return vec->data_ + ((vec->size_-1) * vec->data_size_);
}

/* modifiers */
void *insert_vec(Cvector *vec, size_t pos) {
    if (vec == NULL) {
        return NULL;
    }

    if (0 > pos && pos > vec->size_) {
        return NULL;
    }

    if (vec->size_ >= vec->capacity_) {
        resize_vec(vec);
    }

    void *where = (uint8_t *)vec->data_ + (pos * vec->data_size_);
    memmove(where + vec->data_size_, where, vec->data_size_ * (vec->size_ - pos));

    ++vec->size_;
    set_zero(vec, where);

    return where;
}

void erase_vec(Cvector *vec, size_t pos) {
    if (0 > pos && pos > vec->size_) {
        return;
    }

    void *where = vec->data_ + (pos * vec->data_size_);
    memmove(where, where + vec->data_size_, vec->data_size_ * (vec->size_ - pos));

    --vec->size_;
    void *last = (uint8_t *)vec->data_ + (vec->size_ * vec->data_size_); 
    set_zero(vec, last);
}

void *push_vec(Cvector *vec) {
    if (vec->size_ >= vec->capacity_) {
        resize_vec(vec);
    }

    void *where = (uint8_t *)vec->data_ + (vec->size_ * vec->data_size_); 
    ++vec->size_;

    return where;
}

void pop_vec(Cvector *vec) {
    if (vec->size_ == 0) {
        return;
    }
    
    set_zero(vec, &vec->size_ - vec->data_size_);
    --vec->size_;
}
/* ------------------------------------------------------------------ */
