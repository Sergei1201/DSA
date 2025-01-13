/* Stack implementation in C using a single linked list */ 

/* Strategy */ 
/* 1. Create a structure for a node
   2. Create a linked list itself
   3. Create a new node
   4. Check if the linked list is empty
   5. Push a new node onto the stack
   6. Remove the top node from the stack
   7. Peek at the top node of the stack
   8. Print elements of the stack
  */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Function definition */ 

// Create a structure for a linked list
typedef struct Node {
	int data;
	struct Node *next;
} Node;

// Stack
typedef struct Stack {
	Node *head;
} Stack;

// Initialize a new stack
void initialize_stack(Stack *stack) {
	stack->head = NULL;
}	
// Create a new node
Node* create_new_node(int data) {
	// Dynamically allocate memory on the heap for a new node
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->data = data;
	return new_node;
}

bool is_empty(Stack *stack) {
	return stack->head == NULL;
}

// Push a new node
void push_node(Stack *stack, int data) {
	// Push a new node onto the stack
	Node *new_node = create_new_node(data);
	// Check if the memory allocation for the new node failed
	if (!new_node) {
		printf("Stack overflow");
		return;
	}
	// Link the new node to the head
	new_node->next = stack->head;
	// Shift the head of the linked list to the newly created node
	stack->head = new_node;
}

// Pop the top node from the linked list
void pop_node(Stack *stack) {
	// Check if the stack is empty
	if (is_empty(stack)) {
		printf("Stack is empty\n");
		return;
	} else {
		// Create a temporary node pointing to the head
		Node *temp = stack->head;
	        // Shift the head to the next node
	        stack->head = stack->head->next;
       	        // Free the memory for the temp node
	        free(temp);	       
	}
} 

// Peek at the top node of the stack
void peek_node(Stack *stack) {
	// Check if the stack is empty
	if (is_empty(stack)) {
		printf("The stack is empty");
		return;
	} else {
		printf("The top node: %d\n", stack->head->data);
	}
}

// Print the stack
void print_stack(Stack *stack) {
	Node *temp = stack->head;
	printf("The stack: ");
	while (temp) {
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(void) {
	Stack stack;
	initialize_stack(&stack);
	push_node(&stack, 10);
	push_node(&stack, 20);
	push_node(&stack, 30);
	push_node(&stack, 40);
	push_node(&stack, 50);
	print_stack(&stack);
	peek_node(&stack);
	pop_node(&stack);
	pop_node(&stack);
	print_stack(&stack);
	peek_node(&stack);
	pop_node(&stack);
	pop_node(&stack);
	print_stack(&stack);
	peek_node(&stack);
	pop_node(&stack);
	print_stack(&stack);
	pop_node(&stack);

	return 0;
}
