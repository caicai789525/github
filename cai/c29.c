#include <stdio.h>

int main() {
    int N;
    printf("请输入个位数字的个数: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("输入无效。个位数字的个数必须大于0。\n");
        return 1;
    }

    int digits[N];
    printf("请输入 %d 个个位数字: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &digits[i]);
    }

    int totalSum = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) {
                totalSum += (digits[i] * 10 + digits[j]);
            }
        }
    }

    printf("所有可能组合出的2位数字的和为: %d\n", totalSum);

    return 0;
}
