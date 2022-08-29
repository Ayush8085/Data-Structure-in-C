#include<stdio.h>
#include<stdlib.h>

// Method to print all values of the array
void printArray(int arr[], int sizeOfArray) {
    for(int i=0; i<sizeOfArray; i++) {
        printf("%d ", arr[i]);
    }
}

// Method to search by using binary search
void binarySearch(int arr[], int sizeOfArray, int num) {

    int low = 0;
    int high = sizeOfArray-1;
    int mid;

    while(low <= high) {
        mid = (high+mid)/2;

        if(arr[mid] == num) {
            printf("\n%d is found at location %d ", num, mid);
            return;
        }
        else if(arr[mid] < num) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    printf("\nValue not found!!");
}

int main() {

    int arr[] = {23, 45, 67, 89, 99, 102};
    int sizeOfArray = sizeof(arr)/sizeof(arr[0]);

    int num;
    printf("\nEnter the value you want to search: ");
    scanf("%d", &num);

    printArray(arr, sizeOfArray);
    binarySearch(arr, sizeOfArray, num);

    return 0;
}