#include "../include/cvec_int.h"

#include <stdarg.h>

Cvector *vecint_dinit(size_t size) {
    return vec_dinit(size, sizeof(cint_t));
}

Cvector *vecint_linit(size_t count, ...) {
    Cvector *vec = vecint_dinit(count);

    va_list args;
    va_start(args, count);
    for (size_t i = 0; i < count; ++i) {
        *vecint_push(vec) = va_arg(args, cint_t);
    }
    
    va_end(args);
    return vec;
}

cint_t *vecint_at(Cvector *vec, size_t pos) {
    return (cint_t *)vec_at(vec, pos);
}

cint_t *vecint_front(Cvector *vec) {
    return (cint_t *)vec_front(vec);
}

cint_t *vecint_back(Cvector *vec) {
    return (cint_t *)vec_back(vec);
}

cint_t *vecint_insert(Cvector *vec, size_t pos) {
    return (cint_t *)vec_insert(vec, pos);
}

cint_t *vecint_push(Cvector *vec) {
    return (cint_t *)vec_push(vec);
}
