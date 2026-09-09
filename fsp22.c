// convert decimal number to binary number
#include <stdio.h>

void decimalToBinary(int decimal) {
    if (decimal == 0) {
        printf("0");
        return;
    }

    int binary[32];
    int i = 0;

    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
}

int main() {
    int decimal;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    printf("Binary representation: ");
    decimalToBinary(decimal);
    printf("\n");

    return 0;
}