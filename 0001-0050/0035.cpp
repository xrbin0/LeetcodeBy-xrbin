#include "0000.h"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        if(size == 0)return 0;
        int l = 0, r = size - 1, mid = (l + r) / 2;
        while(l <= r){
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                r = mid - 1;
                mid = (l + r) / 2;
            }else if(nums[mid] < target){
                l = mid + 1;
                mid = (l + r) / 2;
            }
        }
        if(r >= 0 && r < size && nums[r] < target) return l;
        if(r >= 0 && r < size) return r;return l;
    }
};