#include<stdio.h>
#include<string.h>
#include<stdbool.h>

char s[10000];

bool TrueOrFalse(char *str){
    int top = -1;
    for(int i = 0;str[i] != 0;i++){
        char ch = str[i];
        if(ch == '{'||ch == '('||ch == '['){
            s[++top] = ch;
        }else if(ch == '}'||ch == ')'||ch == ']'){
            if(top == -1){
                return false;
            }
            char topchar = s[top];
            if((ch == '}'&&topchar == '{')||(ch == '('&&topchar ==')')||(ch == '['&&topchar == ']')){
                top--;
            }else{
                return false;
            }
        }
    }
    return top == -1;
}

int main(){ 
    printf("请输入");       
    scanf("%s",s);
    if(TrueOrFalse(s)){
        printf("false\n");
    }else{
        printf("true\n");
    }
    return 0;
}