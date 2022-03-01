#include <stdio.h>
#include <stdlib.h>

// Data structure to represent a stack
typedef struct Stack
{
    int maxsize;
    int top;
    float *items;
} Stack;
 
// Utility function to initialize the stack
Stack* newStack(int capacity)
{
    Stack *pStack = (Stack*)malloc(sizeof(Stack));
 
    pStack->maxsize = capacity;
    pStack->top = -1;
    pStack->items = (float*)malloc(sizeof(float) * capacity);
 
    return pStack;
}
 
// Utility function to return the size of the stack
int size(Stack *pStack) {
    return pStack->top + 1;
}
 
// Utility function to check if the stack is empty or not
int isEmpty(Stack *pStack) {
    return pStack->top == -1;
}
 
// Utility function to check if the stack is full or not
int isFull(Stack *pStack) {
    return pStack->top == pStack->maxsize - 1;
}
 
// Utility function to add an element `x` to the stack
int push(Stack *pStack, float x)
{
    // check if the stack is already full. Then inserting an element would
    // lead to stack overflow
    if (isFull(pStack))
    {
        printf("Stack Full!\n");
        return -1;
    }
 
    printf("Inserting %f\n", x);
 
    // add an element and increment the top's index
    pStack->top++;
    pStack->items[pStack->top] = x;
    return 0;
}
 
// Utility function to pop a top element from the stack
int pop(Stack *pStack, float* x)
{
    // check for stack underflow
    if (isEmpty(pStack))
    {
        printf("Stack Empty!\n");
        return -1;
    }
 
    // remove element decrement stack size by 1
    *x = pStack->items[pStack->top];
    pStack->top--;
    
    printf("Removing %f\n", *x);
    return 0;
}
 
// Utility function to peek at top element from the stack
int peek(Stack *pStack, float* x)
{
    // check for stack underflow
    if (isEmpty(pStack))
    {
        printf("Stack Empty!\n");
        return -1;
    }
 
    // return top of stack value
    *x = pStack->items[pStack->top];
    return 0;
}
 
int main()
{
    // create a stack of capacity 5
    Stack *pt = newStack(5);
    float  value;
 
    push(pt, 1.0);
    push(pt, 2.0);
    push(pt, 3.0);
 
    printf("The stack size is %d\n", size(pt));

    peek(pt, &value);
    printf("Top val on stack is %f\n", value);

    pop(pt, &value);
    pop(pt, &value);
    pop(pt, &value);
 
    if (isEmpty(pt)) {
        printf("The stack is empty");
    }
    else {
        printf("The stack is not empty");
    }
 
    return 0;
}
