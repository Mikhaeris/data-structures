#include "../include/cstack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cstack {
    size_t size_;
    size_t capacity_;
    size_t data_size_;
    void *data_;
};

/* ------------- private functions ------------- */
static void stack_error(const char *error) {
    fprintf(stderr, "%s\n", error);
}

static void stack_resize(Cstack *stack) {
    stack->capacity_ *= 2;
    stack->data_ = realloc(stack->data_, stack->capacity_ * stack->data_size_);
    if (stack->data_ == NULL) {
        stack_error("error: bad alloc in realloc_vec");
        exit(1);
    }
}
/* --------------------------------------------- */

/* constructor */
Cstack *stack_init(size_t size, size_t data_size) {
    Cstack *stack = (Cstack *)malloc(sizeof(Cstack)); 
    if (stack == NULL) {
        stack_error("error: bad alloc in stack_init");
        return NULL;
    }

    stack->size_ = 0;
    stack->capacity_ = 10;
    stack->data_size_ = data_size;
    stack->data_ = malloc(stack->capacity_ * stack->data_size_);

    if (stack->data_ == NULL) {
        free(stack);
        stack_error("error: bad alloc in stack_init");
        return NULL;
    }

    return stack;
}

/* destructor */
void stack_destruct(Cstack **stack) {
    free((*stack)->data_);
    free(*stack);
    *stack = NULL;
}

/* element access */
void *stack_top(Cstack *stack) {
    return &stack->size_;
}

/* capacity */
uint8_t stack_empty(Cstack *stack) {
    return (stack->size_ != 0) ? 0 : 1;
}

size_t stack_size(Cstack *stack) {
    return stack->size_;
}

size_t stack_datasize(Cstack *stack) {
    return stack->data_size_;
}

/* modifiers */
void *stack_push(Cstack *stack) {
    if (stack == NULL) {
        return NULL;
    }

    if (stack->size_ >= stack->capacity_) {
        stack_resize(stack);
    }

    void *where = (uint8_t *)stack->data_ + (stack->size_ * stack->data_size_);
    ++stack->size_;

    return where;
}

void stack_pop(Cstack *stack) {
    if (stack == NULL) {
        return;
    }

    if (stack->size_ == 0) {
        return;
    }

    --stack->size_;
}

void stack_swap(Cstack *stack, Cstack *other) {
    Cstack temp = {
        .size_      = stack->size_,
        .capacity_  = stack->capacity_,
        .data_size_ = stack->data_size_,
        .data_      = stack->data_
    };

    stack->size_      = other->size_;
    stack->capacity_  = other->capacity_;
    stack->data_size_ = other->data_size_;
    stack->data_      = other->data_;

    other->size_      = temp.size_;
    other->capacity_  = temp.capacity_;
    other->data_size_ = temp.data_size_;
    other->data_      = temp.data_;
}
