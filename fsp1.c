#include <stdio.h>
int main() {
    int n, i, j;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n); 
int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("The elements in the array are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}