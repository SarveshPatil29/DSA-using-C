#include <stdio.h>
#define max 5
int queue[max];
int front = -1;
int rear = -1;

void enqueue(int element)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = element;
    }
    else if ((rear + 1) % max == front)
    {
        printf("Queue is overflow..\n");
    }
    else
    {
        rear = (rear + 1) % max;
        queue[rear] = element;
    }
}
void dequeue()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is underflow..\n");
    }
    else if (front == rear)
    {
        printf("\nThe dequeued element is %d", queue[front]);

        front = -1;
        rear = -1;
    }
    else
    {
        printf("\nThe dequeued element is %d", queue[front]);
        front = (front + 1) % max;
    }
}

void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is empty..\n");
    }
    else
    {
        printf("\nElements in a Queue are :");
        while (i <= rear)
        {
            printf(" %d", queue[i]);
            i = (i + 1) % max;
        }
    }
    printf("\n");
}

void isFull()
{
    if ((front == rear + 1) || (front == 0 && rear == max - 1))
        printf("\nQueue is full with size %d\n", max);
    else
        printf("\nQueue is not full yet\n");
}

void isEmpty()
{
    if (front == -1)
        printf("\nQueue is empty\n");
    else
        printf("\nQueue isn't empty\n");
}

int main()
{
    int choice = 1, x;
    printf("\nCreated a circular queue of size %d", max);
    while (choice < 6 && choice != 0)
    {
        printf("\nPress 1: Insert an element");
        printf("\nPress 2: Delete an element");
        printf("\nPress 3: Display the queue");
        printf("\nPress 4: Check if the queue is full or not");
        printf("\nPress 5: Check if the queue is empty or not");
        printf("\nPress any other number to exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            printf("Enter the element which is to be inserted :");

            scanf("%d", &x);
            enqueue(x);
            break;

        case 2:
            dequeue();

            break;

        case 3:
            display();
            break;

        case 4:
            isFull();
            break;

        case 5:
            isEmpty();
            break;
        }
    }
    printf("\nExited from the program\n");
    return 0;
}