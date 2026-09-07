// maximum consecutive 1's in a binary array
#include <stdio.h>

int main() {
    int n, i, count = 0, max_count = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array (0 or 1): ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++) {
        if (arr[i] == 1) {
            count++;
            if (count > max_count) {
                max_count = count;
            }
        } else {
            count = 0;
        }
    }
    printf("The maximum consecutive 1's in the array is: %d\n", max_count);
    return 0;
}