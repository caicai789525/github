#include<stdio.h>
#include<math.h>

int main()
{
    int n;
    scanf("%d",&n);
    if(n<=0){
    printf("false");
    }
    while(n>1){
        if(n%4!=0){
            printf("false");
        }
        n/=4;
    }
    printf("true");
    return 0;
}