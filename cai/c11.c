#include<stdio.h>
#include<string.h>

int String(char *str){
    int length = strlen(str);
    for(int i=0;i<length/2;i++){
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}

int main(){
    char str[1000];
    printf("请输入：");
    scanf("%s",&str);
    String(str);
    printf("%s",&str);
    return 0;
}