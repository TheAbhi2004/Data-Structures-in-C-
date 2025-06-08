#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary search tree
struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the binary search tree
struct Node* insert(struct Node* root, int data) 
{
    if (root == NULL) 
    {
        return createNode(data);
    }
    if (data < root->data) 
    {
        root->left = insert(root->left, data);
    } 
    else 
    {
        root->right = insert(root->right, data);
    }
    return root;
}

// Preorder traversal
void preorder(struct Node* root) 
{
    if (root != NULL) 
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder traversal
void inorder(struct Node* root) 
{
    if (root != NULL) 
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Postorder traversal
void postorder(struct Node* root) 
{
    if (root != NULL) 
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Main function
int main() 
{
    struct Node* root = NULL;
    int choice, data;

    // Initialize choice to a non-exiting value
    choice = 0;

    while (1) 
    {
        printf("\nMenu:\n");
        printf("1. Insert a node\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
