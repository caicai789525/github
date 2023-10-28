#include<stdio.h>
#include<string.h>

int theLastwordLength(char *W){
    int length = 0;
    int i = strlen(W) - 1;
    while (i>=0 && W[i] == ' '){
        i--;
    }
    while(i>=0 && W[i] != ' '){
        length++;
        i--;
    }
    return length;
}

int main(){
    char W[10000];
    printf("请输入：");
    scanf("%s",&W);
    int result = theLastwordLength(W);
    printf("%d",result);
    return 0;
}