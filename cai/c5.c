#include <stdio.h>

int n;
void a(int j){
    int ans;
    int isprime = 1;
    for(int i=2; i<=j/2; i++){
        if(j%i==0){
            isprime = 0;
            break;
        }
    }
    if (isprime) {
        printf("%2d\t",j);
        ans++; 
    }
    if (ans == 5) {
            printf("\n");
            ans =0;
        }  
}

int main()
{
    printf("请输入n：");    scanf("%d",&n);
    printf("\n");
    for (int i=2;i<=n;i++){
        a(i);
    }
    
    return 0;
}