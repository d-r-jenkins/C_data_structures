#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

struct queue* init_queue(){
    struct queue* q;
    q = calloc(1, sizeof(struct queue));

    q->count = 0;
    q->front = NULL;
    q->back = NULL;

    return q;
}

bool is_empty(struct queue* q){
    return (q->back == NULL);
}

int enqueue(struct queue* q, void* val){
    struct queue_node* temp;
    temp = calloc(1, sizeof(struct queue_node));

    if (temp == NULL){
        printf("%s\n", "Failure to calloc memory in enqueue.");
        delete_queue(q);
        exit(EXIT_FAILURE);
    }

    temp->value = val;
    temp->next = NULL;

    if (is_empty(q)){
        q->front = temp;
        q->back = temp;
    }
    else{
        q->back->next = temp;
        q->back = temp;
    }
    q->count++;

    return q->count;
}

void* dequeue(struct queue* q){

    if (is_empty(q)){
        printf("%s\n", "Cannot dequeue an empty queue.");
        exit(EXIT_FAILURE);
    }

    struct queue_node* temp;
    temp = q->front;
    void* val = temp->value;
    q->front = q->front->next;
    q->count--;
    free(temp);
    return val;
}

void delete_queue(struct queue* q){
    while(q->count > 0){
        dequeue(q);
    }
    free(q);
}

