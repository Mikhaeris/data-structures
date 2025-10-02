#ifndef CLIST_H
#define CLIST_H

#include <stdlib.h>
#include <stdint.h>

typedef struct Clist Clist;

Clist *list_init(size_t data_size);

#endif /* CLIST_H */
