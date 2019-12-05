#include "0000.h"

int* twoSum(int* nums, int numsSize, int target) {
    int *p = (int*)malloc(sizeof(int) * 2);
    for(int i = 0;i < numsSize;i++){
        for(int j = i + 1;j < numsSize;j++){
            if(nums[i] + nums[j] == target){
                *p = i;
                *(p + 1) = j;
                return p;
            }
        }
    }
    return p;
}