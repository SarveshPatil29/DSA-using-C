#include<stdio.h>   
#include<stdlib.h>  
struct node   
{  
    int data;   
    struct node *next;  
};  
struct node *front;  
struct node *rear;   
void insert();  
void delete();  
void display();  
int main ()  
{  
    int choice;   
    while(choice != 4)   
    {     
        printf("\n*************************Main Menu*****************************\n");  
        printf("\n=================================================================\n");  
        printf("\n1.Insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");  
        printf("\nEnter your choice : ");  
        scanf("%d",& choice);  
        switch(choice)  
        {  
            case 1:  
            insert();  
            break; 

            case 2:  
            delete();  
            break; 

            case 3:  
            display();  
            break; 

            case 4:
            break;

            default:   
            printf("\nEnter valid choice??\n");  
        }  
    }  
    printf("\nExited from the program!!\n\n");
    return 0;
}  

void insert()  
{  
    struct node *ptr;  
    int item;   
      
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW!!\n");  
        return;  
    }  
    else  
    {   
        printf("Enter value : ");  
        scanf("%d",&item);  
        ptr -> data = item;  
        if(front == NULL)  
        {  
            front = ptr;  
            rear = ptr;   
            front -> next = NULL;  
            rear -> next = NULL;  
        }  
        else   
        {  
            rear -> next = ptr;  
            rear = ptr;  
            rear->next = NULL;  
        } 
        printf("\nSuccessfully inserted!!\n");
    }  
}     
void delete ()  
{  
    struct node *ptr;  
    if(front == NULL)  
    {  
        printf("\nUNDERFLOW!!\n");  
        return;  
    }  
    else   
    {  
        ptr = front;  
        front = front -> next;  
        free(ptr);  
        printf("\nSuccessfully deleted!!\n");
    }  
}  
void display()  
{  
    struct node *ptr;  
    ptr = front;      
    if(front == NULL)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\nPrinting values .....\n");  
        while(ptr != NULL)   
        {  
            printf("\n%d",ptr -> data);  
            ptr = ptr -> next;  
        }  
    }  
    printf("\n");  
}