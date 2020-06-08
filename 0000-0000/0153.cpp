#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int sizes = nums.size();
        for(int i = 0;i < sizes - 1;i++){
            if(nums[i] > nums[i+1]) return nums[i+1];
        }
        return nums[0];
    }
};