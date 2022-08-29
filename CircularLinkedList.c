#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head;

// Method to print the list
void printList()
{
    struct node *ptr;

    ptr = head;
    if (ptr == NULL)
    {
        printf("\nThe list is empty!!\n");
    }
    else
    {
        printf("\n[ ");
        while (ptr->next != head)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("%d ]", ptr->data);
    }
}

// Method to insert at the begining
void insertAtBegin()
{
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    int item;

    printf("\nEnter the value to be inserted: ");
    scanf("%d", &item);

    ptr->data = item;
    if (head == NULL)
    {
        head = ptr;
        ptr->next = head;
        printf("\nNode inserted\n");
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        ptr->next = head;
        temp->next = ptr;
        head = ptr;
        printf("\nNode inserted at the begining\n");
    }
}

// Method to insert node at last
void insertAtLast()
{
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    int item;

    printf("\nEnter the value to be inserted: ");
    scanf("%d", &item);

    ptr->data = item;
    if (head == NULL)
    {
        head = ptr;
        ptr->next = head;
        printf("\nNode inserted\n");
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = head;
        printf("\nNode inserted at last\n");
    }
}

// Method to delete the first node
void deleteBegin()
{
    struct node *ptr;

    ptr = head;
    if (ptr == NULL)
    {
        printf("\nNothing to delete!!\n");
    }
    else if (head->next == head)
    {
        head = NULL;
        free(head);
        printf("\nThe only node is deleted\n");
    }
    else
    {
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = head->next;
        free(head);
        head = ptr->next;
        printf("\nNode is deleted from the begining\n");
    }
}

// Method to delete the last node
void deleteLast()
{
    struct node *ptr, *temp;

    ptr = head;
    if (ptr == NULL)
    {
        printf("\nNothing to delete!!\n");
    }
    else if (head->next == head)
    {
        head = NULL;
        free(head);
        printf("\nThe only node is deleted\n");
    }
    else
    {
        while (ptr->next != head)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = head;
        free(ptr);
        printf("\nNode is deleted from the last\n");
    }
}

// Method to search for a data
void search()
{
    struct node *ptr;
    int item, i=0;

    if (head == NULL)
    {
        printf("\nCan't search in an empty list\n");
    }
    else
    {
        printf("\nEnter the value you want to search: ");
        scanf("%d", &item);

        ptr = head;
        while (ptr->next != head)
        {
            if (ptr->data == item)
            {
                printf("\nItem found at %d location\n", i+1);
                return;
            }
            ptr = ptr->next;
            i++;
        }
        printf("\nNo such data present in the list\n");
    }
}

int main()
{

    int choice = 0;

    while (choice != 9)
    {

        printf("\n-----------X----------------");
        printf("\n1 - for the printing the whole list");
        printf("\n2 - for inserting a node at the begining");
        printf("\n3 - for inserting a node at the last");
        printf("\n4 - delete the first node");
        printf("\n5 - delete the last node");
        printf("\n6 - to search an item");
        printf("\n9 - to exit the loop");
        printf("\n-----------X----------------");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printList();
            break;

        case 2:
            insertAtBegin();
            break;

        case 3:
            insertAtLast();
            break;

        case 4:
            deleteBegin();
            break;

        case 5:
            deleteLast();
            break;

        case 6:
            search();
            break;

        case 9:
            exit(0);
            break;

        default:
            printf("\nPlease enter a valid choice!!\n");
            break;
        }
    }

    return 0;
}