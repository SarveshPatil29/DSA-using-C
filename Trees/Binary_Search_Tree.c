#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *deletedNode = NULL;
struct node *root = NULL;

struct node *createNode(int data)
{

    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void insert()
{
    int data = 0;
    printf("Enter the node to insert : ");
    scanf("%d", &data);

    struct node *newNode = createNode(data);

    if (root == NULL)
    {
        root = newNode;
        return;
    }
    else
    {

        struct node *current = root, *parent = NULL;

        while (true)
        {

            parent = current;

            if (data < current->data)
            {
                current = current->left;
                if (current == NULL)
                {
                    parent->left = newNode;
                    return;
                }
            }

            else
            {
                current = current->right;
                if (current == NULL)
                {
                    parent->right = newNode;
                    return;
                }
            }
        }
    }
}

struct node *minNode(struct node *root)
{
    if (root->left != NULL)
        return minNode(root->left);
    else
        return root;
}

struct node *deleteNode(struct node *node, int value)
{
    if (node == NULL)
    {
        return NULL;
    }
    else
    {

        if (value < node->data)
            node->left = deleteNode(node->left, value);

        else if (value > node->data)
            node->right = deleteNode(node->right, value);

        else
        {

            if (node->left == NULL && node->right == NULL)
                node = NULL;

            else if (node->left == NULL)
            {
                node = node->right;
            }

            else if (node->right == NULL)
            {
                node = node->left;
            }

            else
            {

                struct node *temp = minNode(node->right);

                node->data = temp->data;

                node->right = deleteNode(node->right, temp->data);
            }
        }
        return node;
    }
}

void delete ()
{
    int value = 0;
    printf("Enter the node to delete : ");
    scanf("%d", &value);
    deletedNode = deleteNode(root, value);
}

void display(struct node *node)
{

    if (root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    else
    {

        if (node->left != NULL)
            display(node->left);
        printf("%d ", node->data);
        if (node->right != NULL)
            display(node->right);
    }
}

int main()
{

    int choice = 0;
    while (true)
    {
        printf("\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n=====================================================\n");
        printf("\n1. Insert node in the binary search tree\n2. Display binary search tree in inorder traversal\n3. Delete a node\n4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            display(root);
            break;
        case 3:
            delete ();
            break;
        case 4:
            printf("Exiting from the program!!\n\n");
            exit(0);
            break;
        default:
            printf("Please enter valid choice..\n\n");
        }
    }

    return 0;
}