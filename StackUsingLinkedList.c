#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
struct node* head;

// Method to push an element 
void push() {
    struct node* ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    int item;
    printf("\nValue you want to push: ");
    scanf("%d", &item);
    
    ptr->data = item;
    if(head == NULL) {
        ptr->next = NULL;
        head = ptr;
        printf("\nValue is pushed successfully!!\n");
    }
    else {
        ptr->next = head;
        head = ptr;
        printf("\nValue is pushed successfully!!\n");
    }
}

// Method to pop an element
void pop() {
    if(head == NULL) {
        printf("\nUNDERFLOW\n");
    }
    else {
        struct node* ptr;

        ptr = head;
        head = head->next;
        free(ptr);
        printf("\nTop value poped successfully!!\n");
    }
}

// Method to show all the elements
void show() {
    struct node* ptr;
    
    ptr = head;
    if(ptr == NULL) {
        printf("\nStack is empty!!\n");
    }
    else {
        printf("\n[ ");
        while(ptr != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("]");
    }

}

int main() {

    int choice = 0; 

    while(choice != 5) {
        printf("\n---------X---------");
        printf("\n1 - Show all the data");
        printf("\n2 - PUSH an element");
        printf("\n3 - POP an element");
        printf("\n5 - exit the loop");
        printf("\n---------X---------");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            show();
            break;
        
        case 2:
            push();
            break;

        case 3:
            pop();
            break;

        case 5:
            exit(0);
            break;
        
        default:
            printf("\nPlease enter a valid choice!!");
            break;
        }
    }

    return 0;
}