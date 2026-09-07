#include <stdio.h>
int main() {
    int n, k, i, j, temp;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number of times to left rotate the array: ");
    scanf("%d", &k);
    k = k % n; // To handle cases where k is greater than n
    // Left rotating the array by k times
    for (i = 0; i < k; i++) {
        temp = arr[0];
        for (j = 0; j < n-1; j++) {
            arr[j] = arr[j+1];
        }
        arr[n-1] = temp;
    }
    printf("The array after left rotating by %d times is: ", k);
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}