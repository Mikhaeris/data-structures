#include <stdio.h>
#include <stddef.h>

#include "Cvector.h"

typedef int c_type;

int main() {
    const size_t N = 10;
    const size_t int_size = sizeof(c_type);

    /* init vector with size N and type int(sizeof(int)) */
    Cvector *vec = vec_dinit(N, int_size);

    /* use function to get size of vec */
    for (size_t i = 0; i < vec_size(vec); ++i) {
        /* set element in postition i */
        *(c_type *)vec_at(vec, i) = i+1;
    }
    
    /* push element to end vec, size increase by one */
    *(c_type *)vec_push(vec) = 15;

    for (size_t i = 0; i < vec_size(vec); ++i) {
        printf("%d ", *(c_type *)vec_at(vec, i));
    }

    /* required destruct vector */
    vec_destruct(&vec);

    return 0;
}
