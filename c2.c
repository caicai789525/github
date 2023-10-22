#include <stdio.h>

int main() {
    double a, b;

    printf("请输入两门课的成绩：\n");
    scanf("%lf %lf", &a, &b);

    if (a < 0 || a > 100 || b < 0 || b > 100) {
        printf("it is error.\n");
    } else {
        switch ((a >= 60) && (b >= 60)) {
            case 1:
                printf("it is pass.\n");
                break;
            default:
                printf("it is not pass.\n");
                break;
        }
    }

    return 0;
}
