# Implementing stack data structure in Python using OOP linked lists

# Strategy
# 1. Create a node class
# 2. Create a stack class
# 3. In that stack class define methods
# 4. Create an empty stack (initialize the stack using constructor
# 5. Check if the stack is empty
# 6. Push a new node to the stack
# 7. Peek at the top node of the stack
# 8. Pop the top node fron the stack
# 9. Print the stack

# Node class
class Node:

    # Initialize a new node when the class is being instantiated
    def __init__(self, data: int) -> None:
        self.data = data
        self.next = None

# Stack class
class Stack:

    # Initialize an empty stack to get started with
    def __init__(self) -> None:
        self.head = None

    # Methods

    # Check if the stack is empty
    def is_empty(self) -> bool:
        return self.head is None

    # Push a new node to the stack
    def push_node(self, new_data: int) -> object:

        # Allocate memory on the heap for a new node, call the Node constructor
        new_node = Node(new_data)

        # If the memory allocation failed, return
        if (not new_node):
            print(f"Memory allocation failed")
            return

        # Link the new node to the head
        new_node.next = self.head

        # Rearrange the pointer of the head so that it's pointing to the new node
        self.head = new_node
        return new_node

    # Pop the top node from the linked list (stack)
    def pop_node(self):
        
        # Check if the stack is empty
        if (self.is_empty()):
            print("The stack is empty")
            return
            
        # Create a temp variable to point to the head of the stack
        temp = self.head
        print(f"Popped {temp.data}")
        # Shift the head to the next node
        self.head = self.head.next

        # Free memory occupied by temp (the former head)
        del temp
    
    # Peek at the top element
    def peek_top(self):

        # Check if the stack is empty
        if (self.is_empty()):
            print("The stack is empty")
            return

        # Print the top node
        print(f"The top node {self.head.data}")


    # Print the stack
    def print_stack(self):
        temp = self.head
        print("The stack", end=" ")
        while (temp):
            print(temp.data, end=" ")
            temp = temp.next
        print()

if __name__ == '__main__':
    # Instantiate a new stack object
    st = Stack()
    st.push_node(10)
    st.push_node(20)
    st.push_node(30)
    st.push_node(40)
    st.push_node(50)
    st.print_stack()
    st.pop_node()
    st.print_stack()
    st.peek_top()
    st.pop_node()
    st.pop_node()
    st.peek_top() 
    st.print_stack()
