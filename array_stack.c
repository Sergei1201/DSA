/* Creating the stack data structure using arrays in C */

#include <endian.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 1. Define a structure for a stack
// 2. Create an empty stack using struct
// 3. Check if the stack is empty
// 4. Check if the stack is full
// 5. Add an element onto the stack
// 6. Remove an element from the stack
// 7. Print the stack


// Define a constant to determine a max size of a stack
#define MAX 10
// Define a variable which will keep the count of the elements of the stack
int count = 0;

/* Function declaration & prototyping */

// Define a structure of the stack
struct Stack {
	int items[MAX];// Array of elements of the stack
	int top;// The top element of the stack (position)
	};
typedef struct Stack st;

// Create an empty stack
void create_stack(st *s);

// Check if the stack is empty
bool is_empty(st *s);

// Check if the stack is full
bool is_full(st *s);

// Push to the stack
void push_element(st *s, int element);

// Pop from the stack
void pop_element(st *s);

// Print the stack
void print_stack(st *s);



int main(void) {
	// Dynamically allocate memory on the heap for our stack
	st *s = (st *)malloc(sizeof(st));
	// Create an empty stack in this block of memory which we've allocated on the heap
	create_stack(s);	
	// Push elements to the stack
	push_element(s, 5);
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
	print_stack(s);
	pop_element(s);
	// print_stack(s);
	// pop_element(s);
	// pop_element(s);
	// pop_element(s);
	// pop_element(s);
	// pop_element(s);
	// print_stack(s);
	
	return 0;
};

/* Function implementation */

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
		// Increment the index of the array
		s->top++;
		// Add a new element to the array
		s->items[s->top] = element;
	}
	// Increment the count of array's elements by one
	count++;
}

void pop_element(st *s) {
	// Check if the stack is empty
	if (is_empty(s)) {
		printf("The stack is empty\n");
	}
	else {
		// Print the element which we are popping up (the last inserted element according to the LIFO method)		
		printf("The popped element %d \n", s->items[s->top]);

		// Decrement the index of the array by 1
		s->top--;
				}
		// Decrement the count of the array (stack)
		count--;
	}
 
void print_stack(st *s) {
	printf("The stack:\n");
	for (int i = 0; i < count; i++) {
		printf("%d \t", s->items[i]);
	}
	printf("\n");
}

