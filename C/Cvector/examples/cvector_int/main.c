#include "../../include/Cvector.h"

#include "./include/cvec_int.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_vec(Cvector *vec);
void shuffle_vec(Cvector *vec);
void insertion_sort(Cvector *vec);

int main() {
    srand(time(NULL));
    const int size = 10;
    Cvector *vec = vecint_linit(size, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    printf("init vec: ");
    print_vec(vec);

    shuffle_vec(vec);
    printf("shuffle vec: ");
    print_vec(vec);

    insertion_sort(vec);
    printf("insertion sort: ");
    print_vec(vec);

    vec_destruct(&vec);
    return 0;
}

void print_vec(Cvector *vec) {
    for (int i = 0; i < vec_size(vec); ++i) {
        printf("%d ", *vecint_at(vec, i));
    }
    puts("");
}

static void swap(cint_t *a, cint_t *b) {
    cint_t temp = *a;
    *a = *b;
    *b = temp;
}

void shuffle_vec(Cvector *vec) {
    for (size_t last = vec_size(vec)-1; last > 0; --last) {
        size_t rand_val = rand() % (last+1);
        swap(vec_at(vec, rand_val), vec_at(vec, last));
    }
}

void insertion_sort(Cvector *vec) {
    for (size_t i = 1; i < vec_size(vec); ++i) {
        cint_t key = *vecint_at(vec, i);
        ssize_t pos = (ssize_t)i - 1;

        while (pos >= 0 && *vecint_at(vec, pos) >= key) {
            *vecint_at(vec, pos + 1) = *vecint_at(vec, pos);
            --pos;
        }
        *vecint_at(vec, pos + 1) = key;
    }
}
