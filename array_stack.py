# Implementing stack data structure in Python using lists

# Strategy
# 1. Create an empty stack
# 2. Check if the stack is empty
# 3. Push an element onto the stack
# 4. Pop the top element from the stack
# 5. Print the stack

# Create an empty stack
def create_stack() ->list:
    stack = []
    return stack

# Check if the stack is empty
def is_empty(stack: list) -> bool:
    if (len(stack) == 0):
        return True
    else:
        return False

# Push an element onto the stack
def push_element(stack: list, element: int) -> None: 
        stack.append(element)
        print(f"The element pushed: {element}")

# Pop an element from the top of the stack
def pop_element(stack: list) -> None:
    # Check if the stack is empty
    if (is_empty(stack)):
        print(f"The stack is empty")
        return
    else:
        # Otherwise pop the top element from the stack
        print(f"The popped element {stack.pop()}")

# Print the stack
def print_stack(stack: list) -> None:
    print("The stack:", end=' ')
    for element in stack:
        print(element, end=' ')
    print()

if __name__ == '__main__':
    # Create an empty stack
    stack = create_stack()
    # Push elements
    push_element(stack, 5)
    push_element(stack, 10)
    print_stack(stack)
    pop_element(stack)
    pop_element(stack)
    pop_element(stack)
    print_stack(stack)

    


