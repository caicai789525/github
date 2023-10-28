#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num, guess, theTimesToTry  = 0;
    int low = 1000, high = 9999;

    srand(time(NULL));

    num = (rand() % (high - low + 1)) + low;

    printf("来了老弟(-_-!!!)\n");
    printf("数字范围在%d到%d之间\n", low, high);

    do {
        printf("来，让你的数字进来(|*o*|) ");

        if (scanf("%d", &guess) != 1) {
            printf("你是不是有什么大病，猜数字不输入数字\n");
            while (getchar() != '\n');
            continue;
        }
        theTimesToTry ++;

        if (guess < low || guess > high) {
            printf("让你输入%d到%d之间的数字是听不懂吗！！！(-_-)#\n", low, high);
        } else if (guess < num) {
            printf("老弟你太小了($0$)\n");
        } else if (guess > num) {
            printf("哦你太大了(@o@)\n");
        } else {
            printf("恭喜，你猜对了！用了%d次尝试。\n", theTimesToTry );
        }
    } while (guess != num);

    return 0;
}
