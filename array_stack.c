/* Stack data structure using arrays in the C programming language */

/* Strategy */ 
/* 1. Define a constant to figure out the maximum size of the stack 
   2. Define a variable to determine the count of elements of the stack
   3. Define a structure for our stack
   4. Define a function to create an empty stack to get started with
   5. Define a function to check if the stack if empty
   6. Define a function to check if the stack is full
   7. Define a function to push an element onto the stack
   8. Define a function to pop an element from the top of the stack
   9. Define a function to print all the elements of the stack
   10. In the main function dynamically allocate memory on the heap for our stack structure
   11. After we're done with the stack, return memory back to the OS
   */   

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the stack
#define MAX 10

// Define a count of the elements of the stack
int count = 0;

// Create a stack structure 
struct Stack {
	int items[MAX];
        int top;	
};
typedef struct Stack st;

/* Function declaration & prototyping */ 

// Create an empty stack
void create_stack(st *s);

// Check if the stack is empty
bool is_empty(st *s);

// Check if the stack is full
bool is_full(st *s);

// Push an element onto the stack 
void push_element(st *s, int element);

// Pop an element from  the top of the stack 
void pop_element(st *s);


// Print elements of the stack
void print_stack(st *s);

int main(void) {
	// Dynamically allocate memory on the heap for the stack to access elements of the structure through pointers
	st *s = (st *)malloc(sizeof(st));
	// Create an empty stack in this block of memory which we've allocated
	create_stack(s);
	// Push elements
	push_element(s, 10);
	push_element(s, 20);
	push_element(s, 30);
	push_element(s, 40);
	push_element(s, 50);
	push_element(s, 60);
	push_element(s, 70);
	push_element(s, 80);
	push_element(s, 90);
	push_element(s, 100);
	// push_element(s, 200);
	print_stack(s);
	pop_element(s);
	pop_element(s);
	pop_element(s);
	pop_element(s);
	pop_element(s);
	pop_element(s);
	pop_element(s);
	pop_element(s);
	pop_element(s);
	pop_element(s);
	print_stack(s);
	pop_element(s);
	return 0;
}

/* Function definition */ 

void create_stack(st *s) {
    s->top = -1;
}

bool is_empty(st *s) {
	if (s->top == -1) {
		return true;
	} else {
		return false;
	}
}

bool is_full(st *s) {
	if (s->top == MAX - 1) {
		return true;
	} else {
		return false;
	}
}

void push_element(st *s, int element) {
	// Check if the stack is full
	if (is_full(s)) {
		printf("The stack is full\n");
		return;
	 } else {
		 // Increment the top index of the array (stack)
		 s->top++;
		// Push an element at the position top of the array
		s->items[s->top] = element;
		printf("The pushed element: %d\n", s->items[s->top]);
	 }
	// Increment the number of elements of the stack (array)
	count++;
}

void pop_element(st *s) {
	// Check if the stack is empty
	if (is_empty(s)) {
		printf("The stack is empty\n");
		return;
	} else {
		// Print the popped out element to the user
		printf("The popped element %d\n", s->items[s->top]);
		// Decrement the top index of the array (stack)
		s->top--;
	}
	// Decrement the number of elements of the stack (array)
	count--;
}


void print_stack(st *s) {
	printf("The stack:\n");
	for (int i = 0; i < count; i++) {
		printf("%d\t", s->items[i]);
	}
	printf("\n");
}
