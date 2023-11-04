#include <stdio.h>

int jump(int *nums, int numSize) {
    int maxReach = 0;
    int steps = 0;    
    int lastJumpEnd = 0; 

    for (int i = 0; i < numSize - 1; i++) {
        maxReach = (maxReach > i + nums[i]) ? maxReach : (i + nums[i]);
        
        if (i == lastJumpEnd) {
            lastJumpEnd = maxReach;
            steps++;
        }
    }

    return steps;
}

int main() {
    int numSize;
    printf("输入 numSize: ");
    scanf("%d", &numSize);
    
    int nums[numSize];
    printf("输入数组元素: ");
    for (int i = 0; i < numSize; i++) {
        scanf("%d", &nums[i]);
    }

    int result = jump(nums, numSize);
    printf("最少跳跃步数: %d\n", result);
    
    return 0;
}
