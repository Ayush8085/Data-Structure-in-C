#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *pev;
    struct node *next;
};
struct node *head;

// Method to print the list
void printList()
{
    struct node *ptr;

    ptr = head;

    printf("\n[ ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("]");
}

// Method to insert node at the begining
void insertAtBegining()
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));

    int item;

    printf("\nEnter the value to be inserted at the begining: ");
    scanf("%d", &item);

    ptr->data = item;
    if (head == NULL)
    {
        ptr->next = NULL;
        ptr->pev = NULL;
        head = ptr;
        printf("\nNode inserted successfully!!\n");
    }
    else
    {
        ptr->next = head;
        ptr->pev = NULL;
        head = ptr;
        printf("\nNode inserted at the begining\n");
    }
}

// Method to insert a node at last
void insertAtLast()
{
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    int item;

    printf("\nEnter the value to be inserted at last: ");
    scanf("%d", &item);

    ptr->data = item;
    if (head == NULL)
    {
        ptr->next = NULL;
        ptr->pev = NULL;
        head = ptr;
        printf("\nNode inserted successfully!!\n");
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->pev = temp;
        ptr->next = NULL;
        printf("\nNode inserted at the last\n");
    }
}

// Method to insert at random location
void insertAtRandom()
{
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    int item, loc;

    printf("\nEnter the value: ");
    scanf("%d", &item);

    printf("\nAt which location you want to insert: ");
    scanf("%d", &loc);

    ptr->data = item;

    temp = head;
    for (int i = 0; i < loc; i++)
    {
        if (temp->next == NULL)
        {
            printf("\nNode can't be inserted\n");
            return;
        }
        temp = temp->next;
    }
    ptr->next = temp->next;
    temp->next = ptr;
    ptr->pev = temp;
    temp->next->pev = ptr;
    printf("\nNode inserted at location %d\n", loc);
}

// Method to delete the first node
void deleteBegining()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\nThe list is empty!!\n");
    }
    else if (ptr->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nThe only node is deleted\n");
    }
    else
    {
        ptr->next->pev = NULL;
        head = ptr->next;
        free(ptr);
        printf("\nThe first node is deleted!!\n");
    }
}

// Method to delete the last node
void deleteLast()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("\nThe list is empty!!");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nThe only node is deleted\n");
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->pev->next = NULL;
        free(temp);
        printf("\nThe last node is deleted!!\n");
    }
}

// Method to delete at a random location
void deleteRandom()
{
    struct node *ptr, *temp;
    int item;

    printf("\nEnter the data to be deleted: ");
    scanf("%d", &item);

    ptr = head;
    if(ptr == NULL) {
        printf("\nThe list is empty!!\n");
        return;
    }

    while(ptr->data != item) {
        ptr = ptr->next;
        if(ptr->next == NULL) {
            printf("\nCan't be deleted!!\n");
            return;
        }
    }
    temp = ptr->next;
    ptr->next = temp->next;
    temp->next->pev = ptr;
    free(temp);
    printf("\nNode is deleted\n");
}

int main()
{
    int choice = 0;

    while (choice != 9)
    {

        printf("\n-------------X-----------");
        printf("\n1 - for printing the list");
        printf("\n2 - for inserting a node at the begining");
        printf("\n3 - for inserting a node at the last");
        printf("\n4 - for inserting a node at the random location");
        printf("\n5 - to delete the first node");
        printf("\n6 - to delete the last node");
        printf("\n7 - to delete at a specific data");
        printf("\n9 - exit the loop");
        printf("\n-------------X-----------");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printList();
            break;

        case 2:
            insertAtBegining();
            break;

        case 3:
            insertAtLast();
            break;

        case 4:
            insertAtRandom();
            break;

        case 5:
            deleteBegining();
            break;

        case 6:
            deleteLast();
            break;

        case 7:
            deleteRandom();
            break;

        case 9:
            exit(0);
            break;

        default:
            printf("Please enter a valid choice!!!");
        }
    }

    return 0;
}