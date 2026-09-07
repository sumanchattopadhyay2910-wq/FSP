#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int unique[n];
    int k = 0;

    for (int i = 0; i < n; i++) {
        int isDuplicate = 0;
        for (int j = 0; j < k; j++) {
            if (unique[j] == arr[i]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            unique[k++] = arr[i];
        }
    }

    printf("Unique elements are: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", unique[i]);
    }
    return 0;
}