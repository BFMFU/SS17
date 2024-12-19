#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void inputArray(int **arr, int *n);
bool isPrime(int num) ;
void printEvenNumbers(int *arr, int n);
void printPrimeNumbers(int *arr, int n);
void reverseArray(int *arr, int n) ;
void sortArray(int *arr, int n, bool ascending);
void searchElement(int *arr, int n);
int main() {
    int *arr = NULL, n = 0, choice;
    do {
        printf("\nMENU\n");
        printf("1. Input array\n");
        printf("2. Print even numbers\n");
        printf("3. Print prime numbers\n");
        printf("4. Reverse array\n");
        printf("5. Sort array\n");
        printf("6. Search element\n");
        printf("7. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                inputArray(&arr, &n);
                break;
            case 2:
                if (arr) printEvenNumbers(arr, n);
                else printf("Array is empty. Please input the array first.\n");
                break;
            case 3:
                if (arr) printPrimeNumbers(arr, n);
                else printf("Array is empty. Please input the array first.\n");
                break;
            case 4:
                if (arr) reverseArray(arr, n);
                else printf("Array is empty. Please input the array first.\n");
                break;
            case 5:
                if (arr) {
                    int sortChoice;
                    printf("1. Ascending\n");
                    printf("2. Descending\n");
                    printf("Your choice: ");
                    scanf("%d", &sortChoice);
                    if (sortChoice == 1) sortArray(arr, n, true);
                    else if (sortChoice == 2) sortArray(arr, n, false);
                    else printf("Invalid choice.\n");
                } else {
                    printf("Array is empty. Please input the array first.\n");
                }
                break;
            case 6:
                if (arr) searchElement(arr, n);
                else printf("Array is empty. Please input the array first.\n");
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);
    if (arr) free(arr);
    return 0;
}
void inputArray(int **arr, int *n) {
    printf("Enter the number of elements: ");
    scanf("%d", n);
    *arr = (int *)malloc(*n * sizeof(int));
    printf("Enter the elements:\n");
    for (int i = 0; i < *n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &(*arr)[i]);
    }
}
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}
void printEvenNumbers(int *arr, int n) {
    printf("Even numbers: ");
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}
void printPrimeNumbers(int *arr, int n) {
    printf("Prime numbers: ");
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}
void reverseArray(int *arr, int n) {
    printf("Reversed array: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void sortArray(int *arr, int n, bool ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((ascending && arr[i] > arr[j]) || (!ascending && arr[i] < arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void searchElement(int *arr, int n) {
    int x, found = 0;
    printf("Enter the element to search: ");
    scanf("%d", &x);
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("Element %d found at position %d\n", x, i + 1);
            found = 1;
        }
    }
    if (!found) {
        printf("Element %d not found in the array.\n", x);
    }
}
