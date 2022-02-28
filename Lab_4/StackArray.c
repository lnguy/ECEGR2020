#include <stdio.h>
#include <stdlib.h>

// Data structure to represent a stack
typedef struct Stack
{
	float data;
    struct Stack* next;
} Stack;
 
Stack* firstItem = NULL;

Stack* createPlate(float in)
{
	Stack* newElem = (Stack*) malloc(sizeof(Stack));
	
	if(newElem != NULL)
	{
		newElem->data = in;
		newElem->next = NULL;
	}
	
	return newElem;
}
 
// Utility function to return the size of the stack
int size() {
    Stack* node = firstItem;
	int count = 0;
	while(node != NULL)
	{
		count++;
		node = node->next;
	}
	return count;
}
 
// Utility function to check if the stack is empty or not
int isEmpty() {
    return firstItem == NULL;
}
 
// Utility function to check if the stack is full or not
int isFull() {
    return (malloc(sizeof(Stack)) == NULL);
}
 
// Utility function to add an element `x` to the stack
int push(float x)
{
    // check if the stack is already full. Then inserting an element would
    // lead to stack overflow
    if (isFull())
    {
        printf("Stack Full!\n");
        return -1;
    }
	
	Stack* newPlate = createPlate(x);
 
    printf("Inserting %f\n", x);
 
    // add an element and increment the top's index
	if(firstItem == NULL)
	{
		firstItem = newPlate;
		return 0;
	}
	newPlate->next = firstItem;
	firstItem = newPlate;
    return 0;
}
 
// Utility function to pop a top element from the stack
int pop()
{
    // check for stack underflow
    if (isEmpty())
    {
        printf("Stack Empty!\n");
        return -1;
    }
 
    // remove element decrement stack size by 1
	printf("Removing %f\n", firstItem->data);
    Stack* temp = firstItem;
	firstItem = firstItem->next;
	free(temp);
    
    return 0;
}
 
// Utility function to peek at top element from the stack
int peek(float* x)
{
    // check for stack underflow
    if (isEmpty())
    {
        printf("Stack Empty!\n");
        return -1;
    }
 
    // return top of stack value
    *x = firstItem->data;
    return 0;
}
 
int main()
{
    float value;
 
    push(1.0);
    push(2.0);
    push(3.0);
 
    printf("The stack size is %d\n", size());

    peek(&value);
    printf("Top val on stack is %f\n", value);

    pop();
    pop();
    pop();
 
    if (isEmpty()) {
        printf("The stack is empty");
    }
    else {
        printf("The stack is not empty");
    }
 
    return 0;
}
