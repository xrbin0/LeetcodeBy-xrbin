#include "0000.h"

int removeDuplicates(int* nums, int numsSize) {
    if(numsSize == 0) return 0;
    int *a = (int*)malloc(sizeof(int) * numsSize);
    int count = 1;
    a[0] = nums[0];
    for(int i = 0;i < numsSize;i++)
        for(int j = 0;j < count;j++){
            if(nums[i] == a[j])
                break;
            if(j == count - 1){
                a[count] = nums[i];
            count++;}
        }
    for(int i = 0;i < count;i++)
        nums[i] = a[i];
    return count;
}