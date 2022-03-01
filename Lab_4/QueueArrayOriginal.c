#include <stdio.h>
#include <stdlib.h>

// Data structure to represent a queue
typedef struct Queue
{
    int maxsize;
    int size;
    int front;
    int rear;
    float *items;
} Queue;
 
// Utility function to initialize the queue
Queue* newQueue(int capacity)
{
    Queue *pQueue = (Queue*)malloc(sizeof(Queue));
 
    pQueue->maxsize = capacity;
    pQueue->size = 0;
    pQueue->front = 0;
    pQueue->rear  = 0;
    pQueue->items = (float*)malloc(sizeof(float) * capacity);
 
    return pQueue;
}
 
// Utility function to return the size of the queue
int size(Queue *pQueue) {
    return (pQueue->size == 0);
}
 
// Utility function to check if the queue is empty or not
int isEmpty(Queue *pQueue) {
    return (pQueue->size == 0);       
}
 
// Utility function to check if the queue is full or not
int isFull(Queue *pQueue) {
    return (pQueue->size == pQueue->maxsize);  
}
 
// Utility function to add an element `x` to the queue
int insert(Queue *pQueue, float x)
{
    // check if the queue is already full
    if (isFull(pQueue))
    {
        printf("Queue Full!\n");
        return -1;
    }
 
    printf("Inserting %f\n", x);
 
    // add an element to queue
    pQueue->items[pQueue->rear] = x;
    pQueue->rear = (pQueue->rear + 1) % pQueue->maxsize;
    pQueue->size++;
    return 0;
}
 
// Utility function to remove an element from the queue
int removeQueue(Queue *pQueue, float* x)
{
    // check for queue underflow
    if (isEmpty(pQueue))
    {
        printf("Queue Empty!\n");
        return -1;
    }
 
    // remove element decrement queue size by 1
    *x = pQueue->items[pQueue->front];
    pQueue->front = (pQueue->front + 1) % pQueue->maxsize;
    pQueue->size--;
    
    printf("Removing %f\n", *x);
    return 0;
}
 
// Utility function to peek at first element from the queue
int peek(Queue *pQueue, float* x)
{
    // check for queue underflow
    if (isEmpty(pQueue))
    {
        printf("Queue Empty!\n");
        return -1;
    }
 
    // return front of queue value
    *x = pQueue->items[pQueue->front];
    return 0;
}
 
int main()
{
    // create a queue of capacity 5
    Queue *qt = newQueue(5);
    float  value;
 
    insert(qt, 1.0);
    insert(qt, 2.0);
    insert(qt, 3.0);
 
    printf("The queue size is %d\n", size(qt));

    peek(qt, &value);
    printf("Top val on queue is %f\n", value);

    removeQueue(qt, &value);
    removeQueue(qt, &value);
    removeQueue(qt, &value);
 
    if (isEmpty(qt)) {
        printf("The queue is empty");
    }
    else {
        printf("The queue is not empty");
    }
 
    return 0;
}
