#include <stdio.h>
#include <stdlib.h>

char *qijingzhi(int num) {
    if (num == 0) {
        return "0";
    }

    char *result = (char *)malloc(20 * sizeof(char)); 
    int index = 0;
    int isNegative = 0;

    if (num < 0) {
        isNegative = 1;
        num = -num; 
    }

    while (num > 0) {
        int digit = num % 7;
        result[index++] = '0' + digit;
        num /= 7;
    }

    if (isNegative) {
        result[index++] = '-'; 
    }

    result[index] = '\0'; 
    int left = 0, right = index - 1;
    while (left < right) {
        char temp = result[left];
        result[left] = result[right];
        result[right] = temp;
        left++;
        right--;
    }

    return result;
}

int main() {
    int num;
    printf("请输入一个整数: ");
    scanf("%d", &num);
    char *result = qijingzhi(num);
    printf("7进制表示为: %s\n", result);
    free(result); 
    return 0;
}
