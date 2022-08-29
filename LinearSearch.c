#include<stdio.h>
#include<stdlib.h>

// Method to print the array
void printArray(int arr[], int sizeOfArray) {

    for(int i=0; i<sizeOfArray; i++) {
        printf("%d ", arr[i]);
    }
}

// Method to search by using linear searching
void linearSearch(int arr[], int sizeOfArray, int num) {

    for(int i=0; i<sizeOfArray; i++) {
        if(arr[i] == num) {
            printf("\n%d found at %d location!!", num, i);
            return;
        }
    }
    printf("\nValue not found!!");
}

int main() {

    int arr[] = {12, 1, 43, 45, 4};
    int sizeOfArray = sizeof(arr) / sizeof(arr[0]);

    int num;
    printf("\nEnter what you want to search: ");
    scanf("%d", &num);

    printArray(arr, sizeOfArray);
    linearSearch(arr, sizeOfArray, num);

    return 0;
}