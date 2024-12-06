# **Push_swap**

**Push_swap** is a project from École 42 that challenges students to sort a list of integers using two stacks and a limited set of operations. The objective is to sort the data with the fewest possible moves, demonstrating proficiency in algorithm optimization and data structure manipulation.

---

## **Overview**

The project involves creating a program that generates a sequence of operations to sort a stack of integers. Additionally, a checker program verifies the correctness of the sorting operations. The allowed operations include swapping, pushing, and rotating elements between two stacks, `a` and `b`.

---

## **Features**

- **Sorting Algorithm**:
  - Develops an efficient algorithm to sort integers using two stacks and a predefined set of operations.

- **Checker Program**:
  - Validates the sequence of operations to ensure the stack is sorted correctly.

- **Operations**:
  - `sa` (swap a): Swap the first two elements at the top of stack `a`.
  - `sb` (swap b): Swap the first two elements at the top of stack `b`.
  - `ss`: Perform `sa` and `sb` simultaneously.
  - `pa` (push a): Move the top element from stack `b` to stack `a`.
  - `pb` (push b): Move the top element from stack `a` to stack `b`.
  - `ra` (rotate a): Shift all elements of stack `a` up by one.
  - `rb` (rotate b): Shift all elements of stack `b` up by one.
  - `rr`: Perform `ra` and `rb` simultaneously.
  - `rra` (reverse rotate a): Shift all elements of stack `a` down by one.
  - `rrb` (reverse rotate b): Shift all elements of stack `b` down by one.
  - `rrr`: Perform `rra` and `rrb` simultaneously.

---

## **How It Works**

1. **Input Parsing**:
   - The program accepts a list of integers as arguments, representing the initial stack `a`.

2. **Algorithm Execution**:
   - Utilizes sorting algorithms to determine the optimal sequence of operations to sort stack `a`.

3. **Operation Output**:
   - Outputs the sequence of operations required to sort the stack.

4. **Validation**:
   - The checker program reads the initial stack and the sequence of operations, then verifies if the stack is sorted correctly.

---
