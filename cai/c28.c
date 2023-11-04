#include <stdio.h>
#include<stdlib.h>

int findPoisonedDuration(int* time, int timeSize, int duration) {
    if (timeSize == 0) {
        return 0;
    }

    int totalDuration = duration;

    for (int i = 1; i < timeSize; i++) {
        int gap = time[i] - time[i - 1];
        totalDuration += (gap < duration) ? gap : duration;
    }

    return totalDuration;
}

int main() {
    int timeSize;
    printf("攻击次数\n");
    scanf("%d",&timeSize);
   
    int* time = (int*)malloc(timeSize * sizeof(int));

    printf("输入在第几秒攻击\n");
    for (int i = 0;i<timeSize;i++){
        scanf("%d",&time[i]);
    }
    int duration = 3;

    int result = findPoisonedDuration(time, timeSize, duration);

    printf("艾希处于中毒状态的总秒数：%d\n", result);

    return 0;
}
//找不到那里出错了