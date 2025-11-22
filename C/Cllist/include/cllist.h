#ifndef CLLIST_H
#define CLLIST_H

#include <stdlib.h>
#include <stdint.h>

typedef void *iter;

typedef struct Cllist Cllist;

/* constructor */
Cllist *llist_init(size_t data_size);

/* destructor */
void llist_destruct(Cllist **llist);

/* capacity */
uint8_t llist_empty(Cllist *llist);
size_t llist_size(Cllist *llist);
size_t llist_datasize(Cllist *llist);

/* element access */
iter llist_front(Cllist *llist);
iter llist_back(Cllist *llist);
void *llist_val(iter it);
iter llist_atp(Cllist *llist, size_t pos);
iter llist_prev(Cllist *llist, iter node);
iter llist_next(iter node);

/* modifiers */
void llist_clear(Cllist *llist);
void *llist_insert(Cllist *llist, size_t pos);
void llist_erase(Cllist *llist, size_t pos);
void *llist_push_back(Cllist *llist);
void llist_pop_back(Cllist *llist);
void *llist_push_front(Cllist *llist);
void llist_pop_front(Cllist *llist);

#endif /* CLLIST_H */
