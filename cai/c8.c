#include<stdio.h>
#include<stdbool.h>


bool isPalindrome(int x){
    long int a=x,b=0;
    if(x>=0&&x<10)
    return true;
    else if(x<0)
    return false;
    else while(a>0)
    {
        b=b*10+a%10;
        a=a/10;
    }
    if(b==x) return true;
    else return false;
}
