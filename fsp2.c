// This program finds the second largest element in an array of integers entered by the user.
#include <stdio.h>
int main() {
    int n, i, MAX, second_MAX;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    MAX = arr[0];
    second_MAX = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > MAX) {
            second_MAX = MAX;
            MAX = arr[i];
        } else if (arr[i] > second_MAX && arr[i] != MAX) {
            second_MAX = arr[i];
        }
    }
    if (second_MAX == MAX) {
        printf("There is no second largest element in the array.\n");
    } else {
        printf("The second largest element in the array is: %d\n", second_MAX);
    }
    return 0;
}