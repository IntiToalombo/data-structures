// Implements a list of integers as a binary search tree
#include <stdio.h>
#include <stdlib.h>

// Create a node
typedef struct node
{
    int number;
    struct node *right;
    struct node *left;
}
node;

// Function prototypes
void insert_number(node **root, int number);
void print_tree(node *root);
void free_tree(node *root);
int main(int argc, char *argv[])
{
    // Tree of size 0
    node *tree = NULL;
    
    // Check if the there are numbers provided as command line arguments
    if (argc < 2)
    {
        printf("Usage: %s <number1> <number2>....\n",argv[0]);
        return 1;
    }
    // Parse command line and insert into BST
    for (int i = 1; i < argc; i++)
    {
        char *endptr;
        long number = strtol(argv[i], &endptr, 10);
        // Check if the conversion was succesful
        if (*endptr != '\0')
        {
            fprintf(stderr, "%s is not a valid number\n", argv[i]);
            continue;
        }
        insert_number(&tree, number);
    }
    // Print tree
    print_tree(tree);
    // Free tree
    free_tree(tree);
    return 0;
}
void insert_number(node **root, int number)
{
    // Create a new node for the number
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    new_node->number = number;
    new_node->left = NULL;
    new_node->right = NULL;
    // If the tree is empty, make the new node the root
    if (*root == NULL)
    {
        *root = new_node;
        return;
    }
    // Traverse the tree to find the appopiate position to insert the new node
    node *current = *root;
    while (1)
    {
        // If the new number is less than the current node's number, go to lef
        if (number < current->number)
        {
            if (current->left == NULL)
            {
                current->left = new_node;
                return;
            }
            else
            {
                current = current->left;
            }
        }

        // If the new number is greater thant or equal to the current node's number, go to right
        else
        {
            if (current->right == NULL)
            {
                current->right = new_node;
                return;
            }
            else
            {
                current = current->right;
            } 
        }
    }  
}

// Print tree
void print_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    print_tree(root->left);
    printf("%i\n", root->number);
    print_tree(root->right);
}

// Free memory
void free_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}
