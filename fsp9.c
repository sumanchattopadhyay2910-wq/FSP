#include <stdlib.h>
char* largestOddNumber(char* num){
    int n=strlen(num);
    int i;
    for(i=n-1;i>=0;i--){
        int digit = num[i] - '0';
        if(digit%2!=0){
            num[i+1] = '\0';
            return num;
        }
    }
    return "";
}
int main(){
    char str[25];
    printf("Enter the String:");
    get(str);
    char* result = largestOddNumber(str);
    if(result[0]=='\0'){
        printf("No odd number found in the string");
    }
    else{
        printf("Largest odd number in the string is: %s",result);
    }
    return 0;
}