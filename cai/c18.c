#include <stdio.h>

int hammingDistance(int x, int y) {
    int xorResult = x ^ y; 
    int distance = 0;

    while (xorResult > 0) {
        if (xorResult & 1) {
            distance++;
        }
        xorResult >>= 1; 
    }

    return distance;
}

int main() {
    int x, y;

    printf("请输入两个整数 x 和 y: ");
    scanf("%d %d", &x, &y);

    int result = hammingDistance(x, y);
    printf("汉明距离是: %d\n", result);

    return 0;
}
