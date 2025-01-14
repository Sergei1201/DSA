/* Implementing the stack data structure using linked list in C */ 

/* Strategy */ 
/* 1. Define node using struct 
   2. Define stack 
   3. Initialize stack
   4. Check if the stack is empty
   5. Create a new node on the stack
   6. Push a new node onto the stack
   7. Pop the top node from the stack
   8. Peek at the top node of the stack
   9. Print the stack
*/ 

#include <endian.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node data structure 
typedef struct Node {
	int data;
	struct Node *next;
} Node;

// Define stack
typedef struct Stack {
	Node *head;
} Stack;

// Initialize the stack (the default stack will be empty which means the head will point to null
void initialize_stack(Stack *stack) {
	stack->head = NULL;
}

// Check if the stack is empty
bool is_empty(Stack *stack) {
	return stack->head == NULL;
}

// Create a new node
Node* create_new_node(int data) {

	// Memory allocation on the heap for a new node
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->data = data;
	return new_node;
}

// Push a new node onto the stack
void push_node(Stack *stack, int data) {

	// Create new node by calling function defined above
	Node *new_node = create_new_node(data);

	// Make sure the memory has bee allocated properl and no mistakes have occurred during this process
	if (!new_node) {
		printf("Memory allocation error");
		return;
	}	

	// Connect the newly created node to the head
	new_node->next = stack->head;

       // Rearrange the pointer to the new head (new node)
       stack->head = new_node;
       
       // Print the new node added at the top of the stack
       printf("Pushed %d\n", stack->head->data );
}

// Pop the top node from the stack
void pop_node(Stack *stack) {

	// Check if the stack is empty
	if (is_empty(stack)) {
		printf("The stack is empty\n");
		return;
	} else {
		// Create a temporary node pointing to the head
		Node *temp = stack->head;

		// Shift the head to the next node
		stack->head = stack->head->next;

		// Print the node we're popping off of the stack
		printf("Popped %d\t\n", temp->data);
		
		// Free memory occupied by the temp node
		free(temp);
	}
}

// Peek at the top element of the stack
void peek_element(Stack *stack) {

	// Check if the stack is empty
	if (is_empty(stack)) {
		printf("The stack is empty\n");
		return;
	} else {
		printf("The top element %d\t\n", stack->head->data);
	}
}

// Print elements of the stack
void print_stack(Stack *stack) {

	// Create a temp node to traverse through the linked list and print data on each iteration
	// starting from the top of the stack
	printf("Stack: ");
	Node *temp = stack->head;
	while (temp) {
		printf("%d\t", temp->data );
		temp = temp->next;
	}	
	printf("\n");
}

/* Main function */
int main(void) {

// Create a new stack dynamically on the heap at runtime
Stack *st = (Stack *)malloc(sizeof(Stack));

// Initialize the stack
initialize_stack(st);
// Push onto the stack
push_node(st, 10);
push_node(st, 20);
push_node(st, 30);
push_node(st, 40);
push_node(st, 50);
print_stack(st);
peek_element(st);
pop_node(st);
pop_node(st);
pop_node(st);
pop_node(st);
pop_node(st);
pop_node(st);
print_stack(st);
free(st);
return 0;

}

