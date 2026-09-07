// create a array and moving all zero elements to thr end of the array
#include <stdio.h>
int main() {
    int n, i, j = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int temp[n];
    for (i = 0; i < n; i++) {
        if (arr[i] != 0) {
            temp[j++] = arr[i];
        }
    }
    while (j < n) {
        temp[j++] = 0;
    }
    printf("The array after moving all zero elements to the end is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");
    return 0;
}