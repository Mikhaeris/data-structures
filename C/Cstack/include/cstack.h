#ifndef CSTACK_H
#define CSTACK_H

#include <stddef.h>
#include <stdint.h>

typedef struct Cstack Cstack;

/* constructor */
Cstack *stack_init(size_t size, size_t data_size);

/* destructor */
void stack_destruct(Cstack **stack);

/* element access */
void *stack_top(Cstack *stack);

/* capacity */
uint8_t stack_empty(Cstack *stack);
size_t stack_size(Cstack *stack);
size_t stack_datasize(Cstack *stack);

/* modifiers */
void *stack_push(Cstack *stack);
void stack_pop(Cstack *stack);
void stack_swap(Cstack *stack, Cstack *other);

#endif /* CSTACK_H */
