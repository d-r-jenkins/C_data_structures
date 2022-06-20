#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

// Initialise an empty stack
struct stack* init_stack(){
    struct stack* s;
    s = calloc(1, sizeof(struct stack));
    if (s == NULL){
        printf("%s\n", "Failure to calloc memory in init_stack.");
        delete_stack(s);
        exit(EXIT_FAILURE);
    }

    s->count = 0;
    s->top = NULL;

    return s;
}

// pop top value from stack. Returns this value
void* pop_stack(struct stack* s){
    void* val;

    struct stack_node* temp = s->top;
    val = temp->value;

    s->count--;
    s->top = s->top->next;

    free(temp);
    return val;
}

// push element onto stack. Returns number of elements on stack
int push_stack(struct stack* s, void* val){
    struct stack_node* new_node = calloc(1, sizeof(struct stack_node));
    if (new_node == NULL){
        printf("%s\n", "Failure to calloc memory in push_stack.");
        delete_stack(s);
        exit(EXIT_FAILURE);
    }

    new_node->value = val;
    new_node->next = s->top;

    s->count++;
    s->top = new_node;

    return s->count;
}

// check is stack is empty.
bool stack_is_empty(struct stack* s){
    if (s->count == 0){
        return true;
    }
    else {
        return false;
    }
}

//empty and delete stack
void delete_stack(struct stack* s){
    while (!stack_is_empty(s)){
        pop_stack(s);
    }

    free(s);
}

