#include <stdio.h>
#include <stdlib.h>

struct linked_list
{
    int number;
    struct linked_list *next;
    struct linked_list *previous;
};

typedef struct linked_list node;
node *head = NULL, *tail = NULL;

void insert_at_head();
void insert_at_tail();
void delete_head();
void delete_tail();
void print_forward_order();
void print_list();
int getListLength();

int main()
{

    int choice = 0;
    while (choice != 9)
    {
        printf("\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Insert in Beginning\n2.Insert at last\n3.Delete from Beginning\n4.Delete from last\n5.Display\n6.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            insert_at_head();
            break;
        case 2:
            insert_at_tail();
            break;
        case 3:
            delete_head();
            break;
        case 4:
            delete_tail();
            break;
        case 5:
            print_list();
            break;
        case 6:
            printf("Exiting from the program!!\n");
            exit(0);
            break;
        default:
            printf("Please enter valid choice..\n");
        }
    }

    return 0;
}

void insert_at_head()
{
    int number;
    printf("Enter the number to insert : ");
    scanf("%d", &number);
    node *newNode = (node *)malloc(sizeof(node));

    newNode->number = number;
    newNode->next = newNode;
    newNode->previous = newNode;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        newNode->previous = tail;
        head->previous = newNode;
        tail->next = newNode;
        head = newNode;
    }
}

void insert_at_tail()
{
    int number;
    printf("Enter the number to insert : ");
    scanf("%d", &number);
    node *newNode = (node *)malloc(sizeof(node));

    newNode->number = number;
    newNode->next = newNode;
    newNode->previous = newNode;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->next = head;
        newNode->previous = tail;
        tail = newNode;
        head->previous = tail;
    }
}

void delete_head()
{
    if (head == NULL)
        return;

    node *temp = head;

    tail->next = head->next;
    head = head->next;
    head->previous = tail;

    free(temp);
}

void delete_tail()
{
    if (head == NULL)
        return;

    node *temp = head;
    node *current = head;

    while (current->next != head)
    {
        temp = current;
        current = current->next;
    }

    temp->next = head;
    tail = temp;
    head->previous = tail;
    free(current);
}

void print_list()
{
    printf("Displaying values :\n");
    if (head == NULL)
        return;

    node *current = head;

    do
    {
        printf("%d ", current->number);
        current = current->next;
    } while (current != head);

    printf("\nList Length: %d\n", getListLength());
}

void print_forward_order()
{
    if (head == NULL)
        return;

    node *current = head;

    do
    {
        printf("%d ", current->number);
        current = current->next;
    } while (current != head);

    printf("\nList Length: %d\n", getListLength());
}

int getListLength()
{
    if (head == NULL)
        return 0;

    int count = 0;
    node *current = head;

    do
    {
        count++;
        current = current->next;
    } while (current != head);

    return count;
}