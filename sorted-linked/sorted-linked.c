// Implements a sorted linked list of n numbers
#include <stdio.h>
#include <stdlib.h>

// Create the data estructure
typedef struct node
{
    int number;
    struct node *next;
} node;

int main(int argc, char *argv[]) // argv receivs the data from user
{
    // Check correct usage
    if (argc < 2)
    {
        printf("Usage: ./sorted_linked n1 n2 n3 ....\n");
    }
    // Memory for numbers
    node *list = NULL;
    // For each command-line argument
    for (int i = 1; i < argc; i++)
    {
        // Convert string from argv[] to an integer
        int number = atoi(argv[i]);
        // Allocate number for new number
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = number;
        n->next = NULL;
        // If list is empty or new number should be inserted at the beginning
        if (list == NULL || number < list->number)
        {
            // Insert node at the beginnning
            n->next = list;
            list = n;
        }
        // If number belongs later in list
        else
        {
            node *ptr = list;
            // The number value of the next node is less than the number we want to insert
            while (ptr->next != NULL && ptr->next->number < number)
            {
                ptr = ptr->next;
            }
            // After the loop we're at the point where we want to insert our new node
            // Insert node
            n->next = ptr->next;
            ptr->next = n;
        }
    }
    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }
    // Freeing memory
    for (ptr = list; ptr != NULL; ptr = ptr->next)
    {
        node *tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}
