#ifndef CVECTOR_H
#define CVECTOR_H

#include <stdint.h>
#include <stddef.h>

struct Cvector {
    size_t size_;
    size_t capacity_;
    size_t data_size_; 
    void* data_;
};

/* constructor */
void init_vec(struct Cvector *vec, size_t size, size_t data_size);

void destruct_vec(struct Cvector *vec);

/* capacity */
uint8_t empty(struct Cvector *vec);
size_t get_size(struct Cvector *vec);

size_t get_capacity(struct Cvector *vec);

/* element access */
void *at_vec(struct Cvector *vec, size_t pos);

void *front_vec(struct Cvector *vec);

void *back_vec(struct Cvector *vec);

/* modifiers */
void *insert_vec(struct Cvector *vec, size_t pos);

void erase_vec(struct Cvector *vec, size_t pos);

void *push_vec(struct Cvector *vec);

void pop_vec(struct Cvector *vec);

#endif /* CVECTOR_H */
