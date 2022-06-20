#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

// Node for a stack
struct stack_node {
    void* value;
    struct stack_node* next;
};

struct stack {
    int count;
    struct stack_node* top;
};

// Initialise an empty stack
struct stack* init_stack();

// pop top value from stack. Returns this value
void* pop_stack(struct stack* s);

// push element onto stack. Returns number of elements on stack
int push_stack(struct stack* s, void* val); 

// check is stack is empty.
bool stack_is_empty(struct stack* s);

//empty and delete stack
void delete_stack(struct stack* s);

#endif

