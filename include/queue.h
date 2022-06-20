#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>

// Node for a queue
struct queue_node {
    void* value;
    struct queue_node *next;
};

// A queue
struct queue {
    int count; // The number of elements in the queue
    struct queue_node* front; // Pointer to the front of the queue. Elements removed from here.
    struct queue_node* back; // Pointer to the back of the queue. New elements added here.
};

// Initialise an empty queue
struct queue* init_queue(void);

// check if queue is empty
bool is_empty(struct queue* q);

// remove an element from queue. Returns dequeued element.
void* dequeue(struct queue* q);

// add an element to queue. Returns number of elements in queue
int enqueue(struct queue* q, void* value);

// free all memeory in the queue and then the queue itself
void delete_queue(struct queue* q);
#endif
