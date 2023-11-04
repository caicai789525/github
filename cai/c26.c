#include<stdio.h>

int findTheFirstlonlyWord(char *s){
    int count[26] = {0}; 

    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'a']++;
    }

    for (int i = 0; s[i] != '\0'; i++) {
        if (count[s[i] - 'a'] == 1) {
            return i;
        }
    }

    return -1; 
}

int main(){
    char s[100];
    printf("输入s\n");
    scanf("%s",&s);
    int result = findTheFirstlonlyWord(s);
    if (result!=-1){
        printf("%d",result);
    }else{
        printf("没有");
    }
    return 0;
}