#include <stdio.h>
#include <limits.h>

int findtheThirdbigNum(int* nums, int numsSize) {
    long max1 = LONG_MIN, max2 = LONG_MIN, max3 = LONG_MIN;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max1) {
            max3 = max2;
            max2 = max1;
            max1 = nums[i];
        } else if (nums[i] < max1 && nums[i] > max2) {
            max3 = max2;
            max2 = nums[i];
        } else if (nums[i] < max2 && nums[i] > max3) {
            max3 = nums[i];
        }
    }

    if (max3 != LONG_MIN) {
        return (int)max3;
    } else {
        return (int)max1;
    }
}

int main() {
    int nums[1000];
    printf("请输入：\n");   scanf("%s",&nums);
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int thirdMax = findtheThirdbigNum(nums, numsSize);
    printf("第三大的数是: %d\n", thirdMax);

    return 0;
}
