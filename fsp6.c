// create a array then sort it then remove duplicate elements from the array
#include <stdio.h>

int main() {
    int n, i, j, k;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sorting the array
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Removing duplicate elements
    k = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] != arr[i+1]) {
            arr[k++] = arr[i];
        }
    }
    n = k;

    printf("The array after removing duplicate elements is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}