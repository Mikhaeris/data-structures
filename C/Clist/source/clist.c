#include "../include/clist.h"

#include <stdio.h>

typedef struct {
    void *val;
    struct Node *prev;
    struct Node *next;
} Node;

struct Clist {
    size_t size_;
    size_t data_size_;
    Node *head_;
    Node *tail_;
};

/* ------------- private functions ------------- */
static void list_error(const char *error) {
    fprintf(stderr, "%s\n", error);
}
/* --------------------------------------------- */

/* ------------------------ public functions ------------------------ */
/* constructor */
Clist *list_init(size_t data_size) {
    Clist *list = (Clist *)malloc(sizeof(Clist));

    list->size_      = 0;
    list->data_size_ = data_size;
    list->head_      = NULL;
    list->tail_      = NULL;

    return list;
}

/* destructor */
Clist *list_destruct(Clist **list) {
    
}

/* capacity */
uint8_t list_empty(Clist *list) {
    return (list->size_) ? 0 : 1;
}

size_t list_size(Clist *list) {
    return list->size_;
}

size_t list_datasize(Clist *list) {
    return list->data_size_;
}

/* element access */
void *list_atv(Clist *list, size_t pos) {
    if (pos > list->size_) {
        list_error("error: out of range");
        return NULL;
    }
    return NULL;
}

void *list_atp(Clist *list, size_t pos) {
    
}
/* ------------------------------------------------------------------ */
