#include<stdio.h>

void sortColors(int*nums,int numSize){
    int left = 0;
    int right = numSize - 1;
    int i = 0;

    while(i<=right){
        if (nums[i] == 0){
            int temp = nums[i];
            nums[i] = nums[left];
            nums[left] = temp;
            left++;
            i++;
        }else if(nums[i] == 2){
            int temp = nums[i];
            nums[i] = nums[right];
            nums[right] = temp;
            right--;
        }else{
            i++;
        }
    }
}

int main(){
    int numSize;
    printf("请输入numSize\n");
    scanf("%d",&numSize);
    int nums[numSize];
    printf("请输入nums\n");
    for (int i = 0;i<numSize;i++){
        scanf("%d",&nums[i]);
    }
    sortColors(nums,numSize);
    printf("::::\n");
    for (int i = 0;i<numSize;i++){
        printf("%d",nums[i]);
    }
    printf("\n");
    return 0;
}