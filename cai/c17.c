#include <stdio.h>

int arrangeCoins(int n) {
    long left = 0, right = n;

    while (left <= right) {
        long mid = left + (right - left) / 2;
        long sum = mid * (mid + 1) / 2; 
        if (sum == n) {
            return (int)mid; 
        } else if (sum < n) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
    return (int)right;
}

int main() {
    int n;
    printf("请输入硬币数量 n: ");
    scanf("%d", &n);
    int totalRows = arrangeCoins(n);
    printf("可形成完整阶梯行的总行数: %d\n", totalRows);
    return 0;
}
