#ifndef CVECTOR_H
#define CVECTOR_H

#include <stdint.h>
#include <stddef.h>

typedef struct Cvector Cvector;

/* constructor */
Cvector *vec_dinit(size_t size, size_t data_size);

/* destructor */
void vec_destruct(Cvector **vec);

/* capacity */
uint8_t vec_empty(Cvector *vec);
size_t vec_size(Cvector *vec);
size_t vec_capacity(Cvector *vec);
size_t vec_datasize(Cvector *vec);

/* element access */
void *vec_at(Cvector *vec, size_t pos);
void *vec_front(Cvector *vec);
void *vec_back(Cvector *vec);
void *vec_data(Cvector *vec);

/* modifiers */
void *vec_insert(Cvector *vec, size_t pos);
void vec_erase(Cvector *vec, size_t pos);
void *vec_push(Cvector *vec);
void vec_pop(Cvector *vec);

#endif /* CVECTOR_H */
