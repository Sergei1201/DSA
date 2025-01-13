# Stack data structure in Python using lists

# Strategy 
# 1. Create an empty stack using lists
# 2. Check if the stack is empty
# 3. Push an element onto the stack
# 4. Pop an element from the top of the stack
# 5. Pring the stack


# Create an empty stack
def create_stack() -> list:
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
    print(f"The pushed element: {element}")


# Pop from the top of the stack
def pop_element(stack: list) -> None:
    # Check if the stack is empty
    if (is_empty(stack)):
        print(f"The stack is empty")
        return
    else:
        print(f"The poppped element: {stack.pop()}")

# Print the stack
def print_stack(stack) -> None:
    print("The stack: ", end=' ')
    for element in stack:
        print(f"{element}", end=' ')

    print()

if __name__ == '__main__':
    # Create an empty stack
    stack = create_stack()
    # Push elements
    push_element(stack, 10)
    push_element(stack, 20)
    push_element(stack, 30)
    # Print the stack
    print_stack(stack)
    pop_element(stack)
    pop_element(stack)
    pop_element(stack)
    pop_element(stack)
    print_stack(stack)

