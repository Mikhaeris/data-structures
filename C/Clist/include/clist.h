#ifndef CLIST_H
#define CLIST_H

#include <stdlib.h>
#include <stdint.h>

typedef struct Clist Clist;

/* constructor */
Clist *list_init(size_t data_size);

/* destructor */
void list_destruct(Clist **list);

/* element access */
void *list_front(Clist *list);
void *list_back(Clist *list);
void *list_next(void *it);
void *list_atp(Clist *list, void* it, size_t pos);
void *list_val(void *it);

/* capacity */
uint8_t list_empty(Clist *list);
size_t list_size(Clist *list);
size_t list_datasize(Clist *list);

/* modifiers */
void list_clear(Clist *list);
void *list_insert(Clist *list, size_t pos);
void list_erase();
void *list_push_back(Clist *list);
void list_pop_back(Clist *list);
void *list_push_front(Clist *list);
void list_pop_front(Clist *list);
void resize();
void list_swap(Clist *list, void *f, void *s);

#endif /* CLIST_H */
