#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int maxWater = 0; 
    int left = 0;     
    int right = heightSize - 1; 

    while (left < right) {
        int h1 = height[left];
        int h2 = height[right];
        int minHeight = h1 < h2 ? h1 : h2;
        int currentWater = (right - left) * minHeight;

        if (currentWater > maxWater) {
            maxWater = currentWater;
        }

        if (h1 < h2) {
            left++;
        } else {
            right--;
        }
    }

    return maxWater;
}

int main() {
    int n;
    printf("请输入数组大小: ");
    scanf("%d", &n);

    int height[n];

    printf("请输入 %d 个整数作为数组元素:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &height[i]);
    }

    int result = maxArea(height, n);
    printf("最大水容量为: %d\n", result);
    return 0;
}
