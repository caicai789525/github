#include <stdio.h>

int steps(int n){
    int step = 0;

    while(n != 1){
        if (n % 2 == 0){
            n = n / 2;
        }else{
            n = (3 * n + 1) / 2;
        }
        step++;
    }
    return step;
}
int main(){
    int n;
    printf("请输入n:");     scanf("%d",&n);
    if (n <= 0){
        printf("请输入正整数：");
    }else {
        int step = steps(n);
        printf(":%d",step);
    }
    return 0;
}