#include <stdio.h>
int main(){
    int n,i,j;
    char str[MAX][MAX];
    printf("Enter the number of strings: ");
    scanf("%d",&n);
    printf("Enter the strings:\n");
    for(i=0;i<n;i++){
        scanf("%s",str[i]);
    }
    for (j=0;str[0][j]!=\0;j++){
        for(i=1;i<n;i++){
            if(str[i][j]!=str[0][j]){
                str[0][j]='\0';
                break;
            }
            if (str[0][j]=='\0'){
                break;
            }
        }
    }
    printf(" common prefix is: %s\n", str[0]);
    return 0;
}