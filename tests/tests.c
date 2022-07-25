#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"
#include "stack.h"
#include "binary_search_tree.h"

int queue_str_test(void){
    struct queue* q = init_queue();

    enqueue(q, "Hello");
    enqueue(q, ",");
    enqueue(q, "world!");

    char* first = dequeue(q);
    char* second = dequeue(q);
    char* third = dequeue(q);

    printf("%s %s %s\n", first, second, third);

    delete_queue(q);

    return EXIT_SUCCESS;
}

int stack_str_test(void){
    struct stack* s = init_stack();
    push_stack(s, "Hello");
    push_stack(s, ",");
    push_stack(s, "world!");

    char* first = pop_stack(s);
    char* second = pop_stack(s);
    char* third = pop_stack(s);

    printf("%s %s %s\n", first, second, third);

    delete_stack(s);

    return EXIT_SUCCESS;
}

int bst_int_test(void){
    struct bst* tree = bst_init();
    int count;

    printf("initialised bst\n");
    count = bst_add_node(tree, 5);
    count = bst_add_node(tree, 1);

    struct bst_node* mini = bst_get_min(tree);
    printf("%d\n", mini->value);

    bst_delete_node(tree->root);

    return 0;
}

int main(void){
    queue_str_test();
    stack_str_test();
    bst_int_test();

    printf("All tests ran.\n");

    return EXIT_SUCCESS;
}
