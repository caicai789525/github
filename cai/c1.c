#include <stdio.h>

int main() {
    double a, b, c;

    printf("请输入三个实数a,b,c ：\n");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a <= 0 || b <= 0 || c <= 0) {
        printf("0\n");
    } else if (a + b > c && a + c > b && b + c > a) {
        if (a == b && b == c) {
            printf("1\n");
        } else if (a == b || a == c || b == c) {
            printf("2\n");
        } else {
            printf("3\n");
        }
    } else {
        printf("0\n");
    }

    return 0;
}