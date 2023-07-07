# 📚 42 push_swap [![fduque-a's 42 push_swap Score](https://badge42.vercel.app/api/v2/cli4i2e8c001108jt19bvwefz/project/3125610)](https://github.com/JaeSeoKim/badge42)

## Introduction

This project comprises an interesting case study regarding sorting algorithms and its performances, being part of the core curriculum of all 42 schools worldwide. The task is simple: given a sequence of random numbers disposed in a stack data structure (**stack A**), sort them with the help of an empty auxiliary stack (**stack B**) and a set of specific stack operations. The operations allowed are described as follows, as written in our task:

- **`sa`** : **swap a** - Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements).
- **`sb`** : **swap b** - Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements).
- **`ss`** : **`sa`** and **`sb`** at the same time.
- **`pa`** : **push a** - take the first element at the top of b and put it at the top of a. Do nothing if B is empty.
- **`pb`** : **push b** - take the first element at the top of a and put it at the top of b. Do nothing if A is empty.
- **`ra`** : **rotate a** - shift up all elements of stack A by 1. The first element becomes the last one.
- **`rb`** : **rotate b** - shift up all elements of stack B by 1. The first element becomes the last one.
- **`rr`** : **`ra`** and **`rb`** at the same time.
- **`rra`** : **reverse rotate a** - shift down all elements of stack A by 1. The last element becomes the first one.
- **`rrb`** : **reverse rotate b** - shift down all elements of stack B by 1. The last element becomes the first one.
- **`rrr`** : **`rra`** and **`rrb`** at the same time.

### The Push Swap Program

The main objective of the `push_swap` is to print to `STDOUT` the instructions required to sort the **stack A**, which must be given as the program's argument. Each instruction must be followed by a line break (`\n`). The **stack A** must be sorted with its lowest element at the top, while **stack B** must be empty.

```shell
$ ARG='4 0 1 3 2'; ./push_swap $ARG

pb
pb
sa
ra
pa
pa
ra
```

### The Checker Program

To help identify if a set of instructions is valid or not, you can run the `checker` program with the same stack as the `push_swap` program. The `checker` program will then accept the sorting instructions on `STDIN`, giving us the result `OK`, if the stack was indeed sorted, or `KO` otherwise.


```shell
$ ARG='4 0 1 3 2'; ./push_swap $ARG | ./checker $ARG

OK
```

Both the `checker` or `push_swap` executables will result in an error if a stack has non-numerical arguments, a number is repeated or if a number is out of the 8-bit integer range.

---

## Compilation

You must have installed `make` and a C compiler to compile this project. The execution of the `make` command will generate the binary for `push_swap` and `make bonus` will generate the binary of the `checker`.

---

## **Algorithm**

The sorting algorithm used in my code follows a combination of techniques to sort the stack of integers. Here's an explanation of the logic behind the sorting algorithm:

1. **Initialization**:
   - The `create_stack` function reads the input integers and initializes Stack A.
   - It performs error checks for syntax, number range, and repetition.
   - The main function initializes Stack A and Stack B.

2. **Sorting**:
   - If Stack A is not already sorted (`!is_sorted(a)`), the sorting algorithm proceeds.
   - The algorithm differentiates between the sizes of Stack A to determine the sorting strategy:
     - If the size of Stack A is 2, the `sa` function is called to perform the `sa` operation.
     - If the size of Stack A is 3, the `sort_three` function is called to sort the three elements using specific operations.
     - For stack sizes greater than 3, the `push_swap` function is called to sort the stack using a combination of operations.

3. **Sort Three**:
   - The `sort_three` function finds the highest value in Stack A and determines its position relative to the top and the second position of the stack.
   - Based on the position, the function performs the necessary rotations (`ra` or `rra`) to bring the highest value to the bottom.
   - If the top two elements of Stack A are out of order, the function performs the `sa` operation to swap them.

4. **Sort Five**:
   - The `sort_five` function is called when the size of Stack A is 5.
   - It moves elements from Stack A to Stack B until only three elements remain in Stack A.
   - The `set_stuff` function initializes the nodes in both stacks to calculate prices and target nodes.
   - The `finish_rotation` function performs rotations (`ra` or `rra`) to bring the target node to the top of Stack A.
   - The `move_one` function is used to move elements from Stack B to Stack A (`pa` operation).

5. **Sort (for sizes greater than 5)**:
   - The `push_to_b` function is called for stack sizes greater than 5.
   - It moves the smallest half of the elements from Stack A to Stack B and then the remaining until only three elements remain in Stack A.
   - The `sort_three` function is called to sort the remaining three elements in Stack A.
   - The `move_one` function is called to move elements from Stack B back to Stack A (`pa` operation) based on their target nodes and prices.
   - The `set_positions` function sets the position and bottom status of each node in Stack A.
   - The `smallest_node` function is used to find the smallest element in Stack A.
   - The `ra` and `rra` function is used to perform rotations (`ra` or `rra`) to bring the smallest element to the top of Stack A.

6. **Stack and Sort Utilities**:
   - The `utils_algo` and `utils_sort` modules provides utility functions to manipulate stacks, such as appending nodes, determining stack size, checking for sorting, and finding the smallest node. It also sets all the variables we need to know which node we want to move next.

## Found any issues? Contact me! 📥

- Email: fduque-a@student.42porto.com

## Might interest you! :sparkles:

- Check my [42 common-core progress](https://github.com/fduquea/42cursus) :chart_with_upwards_trend:
- My [42 intra profile](https://profile.intra.42.fr/users/fduque-a) :bust_in_silhouette:
