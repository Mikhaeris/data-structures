#include "../include/cllist.h"

#include <stdio.h>

typedef struct Node Node;

struct Node {
    void *val_;
    Node *next_;
};

/* -------------- private functions -------------- */
static Node *node_init() {
    Node *node = (Node *)malloc(sizeof(Node));

    node->val_  = NULL;
    node->next_ = NULL;

    return node;
}

static void node_destruct(Node **node) {
    free((*node)->val_);
    (*node)->next_ = NULL;
    *node = NULL;
}

static void *node_add(Node *node, size_t data_size) {
    return node->val_ = malloc(data_size);
}
/* ----------------------------------------------- */

struct Cllist {
    size_t size_;
    size_t data_size_;
    Node *head_;
    Node *tail_;
};

/* ------------- private functions ------------- */
static void llist_error(const char *error) {
    fprintf(stderr, "%s\n", error);
}
/* --------------------------------------------- */

/* ------------------------ public functions ------------------------ */
/* constructor */
Cllist *llist_init(size_t data_size) {
    Cllist *llist = (Cllist *)malloc(sizeof(Cllist));

    llist->size_      = 0;
    llist->data_size_ = data_size;
    llist->head_      = NULL;
    llist->tail_      = NULL;

    return llist;
}

/* destructor */
void llist_destruct(Cllist **llist) {
    llist_clear(*llist);
    free(*llist);
    *llist = NULL;
}

/* capacity */
uint8_t llist_empty(Cllist *llist) {
    return (llist->size_) ? 0 : 1;
}

size_t llist_size(Cllist *llist) {
    return llist->size_;
}

size_t llist_datasize(Cllist *llist) {
    return llist->data_size_;
}

/* element access */
iter llist_front(Cllist *llist) {
    return llist->head_;
}

iter llist_back(Cllist *llist) {
    return llist->tail_;
}

iter llist_atp(Cllist *llist, size_t pos) {
    if (pos < 0|| pos >= llist->size_) {
        return NULL;
    }

    Node *head = llist->head_;
    for (int i = 0; i < pos; ++i) {
        Node *temp = head;
        head = head->next_;
    }

    return head;
}

void *llist_val(iter it) {
    return ((Node *)it)->val_;
}

iter llist_prev(Cllist *llist, iter node) {
    Node *prev = llist->head_;
    Node *curr = llist->head_->next_;
    while (curr != node && curr != NULL) {
        prev = curr;
        curr = curr->next_;
    }
    return prev;
}

iter llist_next(iter node) {
    return ((Node *)node)->next_;
}

/* modifiers */
void llist_clear(Cllist *llist) {
    Node *head = llist->head_;
    while (head != NULL) {
        Node *temp = head;
        head = head->next_;
        node_destruct(&temp);
    }
    llist->size_ = 0;
    llist->head_ = NULL;
    llist->tail_ = NULL;
}

void *llist_insert(Cllist *llist, size_t pos) {
    if (pos < 0 || pos > llist->size_) {
        return NULL;
    }

    Node *n = node_init();

    if (llist->size_ == 0) {
        llist->head_ = n;
        llist->tail_ = n;
        goto end;
    }

    if (llist->size_ == 1 && pos == 0) {
        n->next_ = llist->head_;
        llist->head_ = n;
        goto end;
    }

    Node *node = llist_atp(llist, pos-1);
    if (llist->size_ == pos) {
        node->next_ = n;
        llist->tail_ = n;
        goto end;
    }

    Node *node_next = node->next_;
    node->next_ = n;
    n->next_ = node_next;

end:
    llist->size_++;
    return node_add(n, llist->data_size_);
}

void llist_erase(Cllist *llist, size_t pos) {
    if (pos < 0 || pos >= llist->size_) {
        goto end;
    }

    if (llist->size_ == 1) {
        node_destruct(&llist->head_);
        llist->head_ = NULL;
        llist->tail_ = NULL;
        goto end;
    }

    if (pos == 0) {
        Node *temp = llist->head_;
        llist->head_ = llist->head_->next_;
        node_destruct(&temp);
        goto end;
    }

    if (pos == (llist->size_ - 1)) {
        Node *temp = llist_atp(llist, pos-1);
        node_destruct(&llist->tail_);
        llist->tail_ = temp;
        goto end;
    }

    Node *prev = llist_atp(llist, pos-1);
    Node *curr = prev->next_;
    Node *next = curr->next_;

    prev->next_ = next;
    node_destruct(&curr);

end:
    llist->size_--;
}

void *llist_push_back(Cllist *llist) {
    Node *n = node_init();

    if (llist->size_ == 0) {
        llist->head_ = n;
        llist->tail_ = n;
        goto end;
    }

    llist->tail_->next_ = n;
    llist->tail_ = n;

end:
    llist->size_++;
    return node_add(n, llist->data_size_);
}

void llist_pop_back(Cllist *llist) {
    if (llist->size_ == 0) {
        return;
    }

    if (llist->size_ == 1) {
        node_destruct(&llist->tail_);
        llist->tail_ = NULL;
        llist->head_ = NULL;
        goto end;
    }
    
    Node *prev_tail = llist_atp(llist, llist->size_-2);
    node_destruct(&llist->tail_);
    llist->tail_ = prev_tail;

end:
    llist->size_--;
}

void *llist_push_front(Cllist *llist) {
    Node *n = node_init();

    if (llist->size_ == 0) {
        llist->head_ = n;
        llist->tail_ = n;
        goto end;
    }

    n->next_ = llist->head_;
    llist->head_ = n;

end:
    llist->size_++;
    return node_add(n, llist->data_size_);
}

void llist_pop_front(Cllist *llist) {
    if (llist->size_ == 0) {
        return;
    }

    if (llist->size_ == 1) {
        node_destruct(&llist->tail_);
        llist->tail_ = NULL;
        llist->head_ = NULL;
        goto end;
    }
    
    Node *next_head = llist->head_->next_;
    node_destruct(&llist->head_);
    llist->head_ = next_head;

end:
    llist->size_--;
}
/* ------------------------------------------------------------------ */
