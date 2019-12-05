#include "0000.h"


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int size = nums.size();
        if(size == 0)return 0;
        int fir = 0;
        for(int i = 0;i < size + 1;i++){
            if(nums[(fir-1+size)%size] > nums[fir])break;
            fir = (fir + 1) % size;
        }
        int l = 0, r = size - 1;int mid = (l + r)/2;
        while(l <= r){
            if(nums[(mid+fir)%size] == target)return 1;
            else if(nums[(mid+fir)%size] > target){
                r = mid-1;
                mid = (l + r)/2;
            
            else if(nums[(mid+fir)%size] < target){
                l = mid+1;
                mid = (l + r)/2;
            }
        }
        return 0;
    }
};