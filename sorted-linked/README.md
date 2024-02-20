# Sorted Linked List
This program implements a sorted linked list of n numbers. It takes command-line arguments n1, n2, n3, ..., nn, and creates a sorted linked list from them.
## Features
* The program creates a sorted linked list from the provided numbers.
* It uses a simple linked list data structure to maintain the sorted order.
* Numbers are inserted into the linked list in ascending order.
* Memory for each node in the linked list is dynamically allocated using `malloc()`.
* After printing the sorted list, memory allocated for each node is freed using `free()` to prevent memory leaks.
## How to run
1. Clone the reposoritory or download the code.
2. Compile the code: gcc `sorted-linked.c -o sorted-linked`
3. Run the the executable, providinf integers as command-line arguments: `./sorted-linked 5 2 8 0 3`
4. The program will print the sorted list of integers:
```
0
2
3
5
8
```
## Code structure:
* `node.h`: Defines the node struture holding an integer and a pointer to the next node.
* `sorted-linked.c`: Implements the main logic for creating, inserting, printing, and freeing the linked list.
* `atoi` function: Converts strings from command-linne arguments to integers.
