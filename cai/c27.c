#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[low];
        int i = low;
        int j = high;
        
        while (i < j) {
            while (arr[i] <= pivot && i < high) {
                i++;
            }
            while (arr[j] > pivot) {
                j--;
            }
            if (i < j) {
                swap(&arr[i], &arr[j]);
            }
        }

        swap(&arr[low], &arr[j]);
        
        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    quickSort(g, 0, gSize - 1);
    quickSort(s, 0, sSize - 1);

    int childIndex = 0;
    int cookieIndex = 0;
    int satisfiedChildren = 0;

    while (childIndex < gSize && cookieIndex < sSize) {
        if (s[cookieIndex] >= g[childIndex]) {
            satisfiedChildren++;
            childIndex++;
        }
        cookieIndex++;
    }

    return satisfiedChildren;
}

int main() {
    int g[100];
    int s[100];
    int gSize,sSize;
    printf("几个孩子\n");
    scanf("%d",&gSize);
    printf("输入每个孩子的满足数量\n");
    for (int i = 0;i<gSize;i++){
        scanf("%d",&g[i]);
    }
    printf("几个饼干\n");
    scanf("%d",&sSize);
    printf("输入每个饼干的大小");
    for (int i = 0;i<sSize;i++){
        scanf("%d",&s[i]);
    }

    int result = findContentChildren(g, sizeof(g) / sizeof(g[0]), s, sizeof(s) / sizeof(s[0]));

    printf("最大能满足的孩子数量：%d\n", result);

    return 0;
}
//输出不知道为什么是错的（ToT），让chatgpt检查也说没问题