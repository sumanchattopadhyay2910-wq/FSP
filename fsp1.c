// This program finds the largest element in an array of integers entered by the user.
#include <stdio.h>
int main() {
    int n, i, MAX;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    MAX = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > MAX) {
            MAX = arr[i];
        }
    }
    printf("The largest element in the array is: %d\n", MAX);
    return 0;
}