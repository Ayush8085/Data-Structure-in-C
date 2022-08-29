#include<stdio.h>
#include<stdlib.h>

int stack[15];
int stackSize;
int choice = 0;
int top = -1;

// Method to perform PUSH
void push() {

    if(top == stackSize) {
        printf("\nOVERFLOW\n");
        return;
    }
    else {
        int value;

        printf("\nValue you want to push: ");
        scanf("%d", &value);

        top = top + 1;
        stack[top] = value;
        printf("\nValue Pushed successfully!!\n");

    }
}

// Method to perform POP
void pop() {

    if(top == -1) {
        printf("\nUNDERFLOW\n");
    }
    else {
        top = top - 1;
        printf("\nTop value poped successfully!!\n");
    }
}

// Method to show all the values of the stack
void show() {
    if(top == -1) {
        printf("\nStack is empty\n");
        return;
    }
    else {
        printf("\n[ ");
        for(int i=top; i>=0; i--) {
            printf("%d ", stack[i]);
        }
        printf("]");
    }
}

int main() {

    printf("\nEnter the size of the stack: ");
    scanf("%d", &stackSize);

    while(choice != 5) {

        printf("\n--------X----------");
        printf("\n1 - PUSH");
        printf("\n2 - POP");
        printf("\n3 - show");
        printf("\n--------X----------");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            show();
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