#include "../include/clist.h"

#include <stdio.h>

typedef struct Node Node;

struct Node {
    void *val;
    Node *prev;
    Node *next;
};

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
void list_destruct(Clist **list) {
    list_clear(*list);
    free(*list);
}

/* element access */
void *list_front(Clist *list) {
    return list->head_;
}

void *list_back(Clist *list) {
    return list->tail_;
}

void *list_next(void *it) {
    return ((Node *)it)->next;
}

void *list_atp(Clist *list, void* it, size_t pos) {
    if (pos > list->size_) {
        list_error("error: out of range");
        exit(1);
    }
    for (int i = 0; i < pos; ++i) {
        it = list_next(it);
    }
    return it;
}

void *list_val(void *it) {
    return &((Node *)it)->val;
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

/*void *list_atv(Clist *list, size_t pos) {
    if (pos > list->size_) {
        list_error("error: out of range");
        return NULL;
    }
    return NULL;
}*/


/* modifiers */
void list_clear(Clist *list) {
    Node *head = list->head_;
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}

void *list_insert(Clist *list, size_t pos) {
    if (pos > list_size(list)) {
        list_error("error: out of range");
        exit(1);
    }

    Node *n = (Node *)malloc(sizeof(Node));

    if (pos == 0 && list->size_ == 0) {
        list->head_ = n;
        list->tail_ = n;
        goto end;
    }

    if (pos == 0) {
        n->next = list->head_;
        n->prev = NULL;
        list->head_->prev = n;
        list->head_ = n;
        goto end;
    }

    Node *prev = list_atp(list, list->head_, pos-1);

    if (pos == list->size_) {
        prev->next = n;
        n->prev = prev;
        n->next = NULL;
        list->tail_ = n;
        goto end;
    }

    Node *next = prev->next;

    prev->next = n;
    n->prev = prev;
    next->prev = n;
    n->next = next;

end:
    list->size_++;
    return &n->val;
}

void list_erase();

void *list_push_back(Clist *list) {
    Node *n = (Node *)malloc(sizeof(Node));
    
    if (list->size_ == 0) {
        list->head_ = n;
        list->tail_ = n;
        goto end;
    }

    list->tail_->next = n;
    n->prev = list->tail_;
    list->tail_ = n;

end:
    list->size_++;
    return &n->val;
}

void list_pop_back(Clist *list) {
    if (list->size_ == 0) {
        return;
    }

    Node *tail = list->tail_;
    Node *prev = list->tail_->prev;
    free(tail);

    list->tail_ = prev;
    list->size_--;
}

void *list_push_front(Clist *list) {
    Node *n = (Node *)malloc(sizeof(Node));

    if (list->size_ == 0) {
        list->head_ = n;
        list->tail_ = n;
        goto end;
    }

    list->head_->prev = n;
    n->next = list->head_;
    list->head_ = n;

end:
    list->size_++;
    return &n->val;
}

void list_pop_front(Clist *list) {
    if (list->size_ == 0) {
        return;
    }

    Node *head = list->head_;
    Node *next = list->head_->next;
    free(head);

    list->head_ = next;
    list->size_--;
}

void resize();

void list_swap(Clist *list, void *f, void *s) {
    if (f == list->head_) {
        list->head_ = s;
    }

    if (s == list->tail_) {
        list->tail_ = f;
    }

    ((Node *)f)->prev = (Node *)s;
    ((Node *)f)->next = NULL;

    ((Node *)s)->prev = f;
    ((Node *)s)->next = NULL;
}

/* ------------------------------------------------------------------ */
