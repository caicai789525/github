#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;

    printf("请输入两个正整数：\n");
    scanf("%d %d", &num1, &num2);

    if (num1 > 0 && num2 > 0) {
        int result = gcd(num1, num2);
        printf("最大公因子是：%d\n", result);
    } else {
        printf("请输入两个正整数。\n");
    }

    return 0;
}
