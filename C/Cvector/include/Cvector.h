#ifndef CVECTOR_H
#define CVECTOR_H

#include <stdint.h>
#include <stddef.h>

typedef struct Cvector Cvector;

/* constructor */
Cvector *dinit_vec(size_t size, size_t data_size);
Cvector *cinit_vec(Cvector *vec);
void destruct_vec(Cvector *vec);

/* capacity */
uint8_t empty(Cvector *vec);
size_t get_size(Cvector *vec);
size_t get_capacity(Cvector *vec);

/* element access */
void *at_vec(Cvector *vec, size_t pos);
void *front_vec(Cvector *vec);
void *back_vec(Cvector *vec);

/* modifiers */
void *insert_vec(Cvector *vec, size_t pos);
void erase_vec(Cvector *vec, size_t pos);
void *push_vec(Cvector *vec);
void pop_vec(Cvector *vec);

#endif /* CVECTOR_H */
