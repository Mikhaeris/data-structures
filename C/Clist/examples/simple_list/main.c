#include "clist.h"

#include <stdio.h>

int main() {
    Clist *clist = list_init(sizeof(int));

    for (size_t i = 0; i < 0; ++i) {
        *(int *)list_push_back(clist) = i+1;
    }

    printf("size: %d\n", list_size(clist));

    void *it = list_front(clist);
    for (size_t i = 0; i < list_size(clist); ++i) {
        int val = *(int *)list_val(it);
        printf("%d ", val);
        it = list_next(it);
    }
    printf("\n");
    
    list_destruct(&clist);
    return 0;
}

