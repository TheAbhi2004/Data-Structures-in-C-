#include <stdio.h>
#include <stdlib.h>

// Definition of a BST node
struct Node 
{
    int key;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int key) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node with given key
struct Node* insert(struct Node* node, int key) 
{
    if (node == NULL) 
    return newNode(key);
    
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    
    return node;
}

// Function to find the minimum value node in a given BST
struct Node* minValueNode(struct Node* node) 
{
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    
    return current;
}

// Function to delete a node with given key
struct Node* deleteNode(struct Node* root, int key) 
{
    if (root == NULL) 
    return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else 
    {
        if (root->left == NULL) 
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL) 
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Function to do inorder traversal of BST
void inorder(struct Node* root) 
{
    if (root != NULL) 
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Driver code
int main() 
{
    struct Node* root = NULL;
    int choice, key;

    while (1) 
    {
        printf("\nMenu:\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Inorder traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                printf("Inserted %d into the BST.\n", key);
                break;
            case 2:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                printf("Deleted %d from the BST.\n", key);
                break;
            case 3:
                printf("Inorder traversal of the BST: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
