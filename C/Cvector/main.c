#include "./Cvector.h"

#include <stdio.h>

void print_vec(struct Cvector *vec, size_t size);

int main() {
    struct Cvector vec;
    const int SIZE = 10;
    init_vec(&vec, SIZE, sizeof(long));
   
    for (int i = 0; i < SIZE; ++i) {
        *(long *)push_vec(&vec) = i;
    }

    print_vec(&vec, get_size(&vec));

    *(long *)insert_vec(&vec, 4) = 9;
    print_vec(&vec, get_size(&vec));

    printf("front: %ld\n", *((long *)front_vec(&vec)));
    printf("back: %ld\n", *(long *)back_vec(&vec));

    erase_vec(&vec, 4);
    print_vec(&vec, get_size(&vec));

    destruct_vec(&vec);
    return 0;
}

void print_vec(struct Cvector *vec, size_t size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", *(int *)at_vec(vec, i));
    }
    printf("\n");
}
