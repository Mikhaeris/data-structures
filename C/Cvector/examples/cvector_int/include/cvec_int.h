#ifndef CVEC_INT_H
#define CVEC_INT_H

#include "../../../include/Cvector.h"
#include "./types.h"

#include <stdint.h>

/* functions for vec int */
Cvector *vecint_dinit(size_t size);
Cvector *vecint_linit(size_t size, ...);

cint_t *vecint_at(Cvector *vec, size_t pos);
cint_t *vecint_front(Cvector *vec);
cint_t *vecint_back(Cvector *vec);

cint_t *vecint_insert(Cvector *vec, size_t pos);
cint_t *vecint_push(Cvector *vec);

/* or macros */
#define VECINT_DINIT(SIZE) vec_dinit(SIZE, sizeof(cint_t))

#define VECINT_AT(VEC, POS) (cint_t *)vec_at(VEC, POS)
#define VECINT_FRONT(VEC) (cint_t *)vec_front(VEC)
#define VECINT_BACK(VEC) (cint_t *)vec_back(VEC)

#define VECINT_INSERT(VEC, POS, VAL) \
    (cint_t *)vec_insert(VEC, POS) = VAL

#define VECINT_PUSH(VEC, VAL) (cint_t *)vec_push(VEC) = VAL

#endif /* CVEC_INT_H */
