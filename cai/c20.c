#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char get(){
    char s[] = {'p', 'r', 's'};
    char randomIndex = rand() % 3;
    return s[randomIndex];
}

int whoisWinner(char u,char c){
    if (u == c){
        printf("平局");
    }
    else if((u == 'p' && c == 's')||
            (u == 's' && c == 'r')||
            (u == 'r' && c == 'p')        
    ){
        printf("你赢了");
    }
    else{
        printf("你输了");
    }
}

int main (){
    char u,c;
    srand(time(NULL));
    printf("请输入:p=布,s=石头,r=剪刀\n");     scanf("%c",&u);    
    scanf("%c",&c);
    c = get();
    printf("%c\n",c);
    whoisWinner(u,c);
    return 0;
}