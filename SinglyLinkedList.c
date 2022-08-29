#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head;

// Method for printing the list
void printList()
{
    struct node *n = head;

    if (n == NULL)
    {
        printf("\nThe list is empty!!\n");
    }
    else
    {
        printf("\n[");
        while (n != NULL)
        {
            printf(" %d ", n->data);
            n = n->next;
        }
        printf("]\n");
    }
}

// Method to insert node at the start of the list
void insertAtBegining()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    int item;

    printf("\nEnter the element you want to insert: ");
    scanf("%d", &item);

    ptr->data = item;
    ptr->next = head;

    head = ptr;
    printf("\nNode inserted at the begining\n");
}

// Method to insert at the end of the list
void insertAtLast()
{
    struct node *ptr, *temp;

    ptr = (struct node *)malloc(sizeof(struct node));

    int item;
    printf("\nEnter the data: ");
    scanf("%d", &item);

    ptr->data = item;
    if (head == NULL)
    {
        ptr->next = head;

        head = ptr;
        printf("\nNode inserted\n");
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = NULL;
        printf("\nNode inserted at end\n");
    }
}

// Method to insert at a random location
void insertAtRandom()
{
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    int item, loc;

    printf("\nAt which location you want to insert: ");
    scanf("%d", &loc);

    printf("\nEnter the value: ");
    scanf("%d", &item);

    ptr->data = item;
    if (head == NULL)
    {
        ptr->next = head;

        head = ptr;
        printf("\nNode inserted\n");
    }
    else
    {
        temp = head;
        for (int i = 0; i < loc; i++)
        {
            temp = temp->next;
            if (temp->next == NULL)
            {
                printf("\nValue can't be inserted");
                return;
            }
        }
        ptr->next = temp->next;
        temp->next = ptr;
        printf("\nNode inserted at %d\n", loc);
    }
}

// Method to delete node from the begining
void deleteBegining()
{
    struct node *ptr;

    if (head == NULL)
    {
        printf("\nList is empty!!!\n");
    }
    else
    {
        ptr = head;

        head = ptr->next;
        free(ptr);
        printf("\n Node deleted from the begining\n");
    }
}

// Method to delete node from the last
void deleteLast()
{
    struct node *ptr, *ptr1;

    if (head == NULL)
    {
        printf("\nList is empty!!!");
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = NULL;
        free(ptr);
        printf("\nNode deleted from the last\n");
    }
}

// Method to delete node at random location
void deleteRandom()
{
    struct node *ptr, *ptr1;
    int loc;

    printf("\nAt which location you want to delete: ");
    scanf("%d", &loc);

    if (head == NULL)
    {
        printf("\nList is empty!!!\n");
    }
    else
    {
        ptr = head;
        for (int i = 0; i < loc; i++)
        {
            ptr1 = ptr;
            ptr = ptr->next;
            if (ptr->next == NULL)
            {
                printf("\nCan't be deleted!!!");
                return;
            }
        }
        ptr1->next = ptr->next;
        free(ptr);
        printf("\nNode deleted at location %d \n", loc);
    }
}

// Method to search a node
void search()
{
    struct node *ptr;
    int item, loc = 0, flag = 0;

    printf("\nEnter the data to search for: ");
    scanf("%d", &item);

    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data == item)
        {
            flag = 1;
        }
        loc++;
        ptr = ptr->next;
    }
    if (flag == 1)
    {
        printf("\nData found at location %d", loc);
    }
    else
    {
        printf("\nData is not found!!!\n");
    }
}

int main()
{
    int choice = 0;
    while (choice != 9)
    {
        printf("\n---------------X-------------");
        printf("\n1 - for inserting the data at begining");
        printf("\n2 - display the data in the list");
        printf("\n3 - for inserting the data at last");
        printf("\n4 - for inserting the data at random");
        printf("\n5 - delete node at the begining");
        printf("\n6 - delete node at the last");
        printf("\n7 - delete node at the random");
        printf("\n8 - to search a data");
        printf("\n9 - to exit the loop");
        printf("\n---------------X-------------");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertAtBegining();
            break;

        case 2:
            printList();
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

        case 8:
            search();
            break;

        case 9:
            exit(0);
            break;

        default:
            printf("\nPlease give a valid choice!!!");
            break;
        }
    }

    return 0;
}
