# Binary Search Tree (BST) for Integer Numbers
This is a simple program using binary search tree (BST) to store integer numbers. It allows the user to input a list of integer numbers as command-line arguments to build a BST and print them in ascending order.
## Features
* It defines a node structure for the BST, containing an integer number and pointers to the left and right child nodes.
* The `insert_number` function inserts a new number into the BST while maintaining its binary search tree property.
* The `print_tree` function traverses the BST in-order and prints the numbers in ascending order.
* The `free_tree` function deallocates the memory used by the BST nodes to prevents memory leaks.
## How to run
1. Compile the program using a C compiler.
   ```
   gcc bst.c -o bst
   ```
3. Run the compiles program, providing a list of integer numbers as command-line arguments:
   ```
   ./bst <number1> <number2> ...
   ```
Where `<number1>`, `<number2>`, and so on are the numbers that you want to insert into BST.
## Example
Create a BST with the numbers -3, 7, 2, -1, and -5. 
```
./bst -3 7 2 -1 5
```
The program will built the BST and print the list of integers in ascending order:
```
-3
-1
2
5
7
```
If the user inputs non-numeric values:
```
./bst -3 7 e -1 %
```
The program should print:
```
e is not a valid number
% is not a valid number
-3
-1
7
```
## Requirements
The program requires a C compiler (e.g., gcc) to compile and run.

   
