#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> dp1 = nums, dp2 = nums;
        if(nums[0] == 0){
            dp1[0] = dp2[0] = 0;
        }
        else if(nums[0] > 0){
            dp1[0] = nums[0];
            dp2[0] = 0;
        }
        else if(nums[0] < 0){
            dp2[0] = nums[0];
            dp1[0] = 0;
        }
        int res = nums[0], size = nums.size(); 
        for(int i = 1;i < size;i++){
            if(nums[i] == 0){
                dp1[i] = dp2[i] = 0;
            }
            else if(nums[i] > 0){
                if(dp1[i - 1] == 0) dp1[i] = nums[i];
                else dp1[i] = dp1[i - 1] * nums[i];
                if(dp2[i - 1] == 0) dp2[i] = 0;
                else dp2[i] = dp2[i - 1] * nums[i];
            }
            else if(nums[i] < 0){
                if(dp1[i - 1] == 0) dp2[i] = nums[i];
                else dp2[i] = dp1[i - 1] * nums[i];
                if(dp2[i - 1] == 0) dp1[i] = 0;
                else dp1[i] = dp2[i - 1] * nums[i];
            }
            res = res > dp1[i] ? res : dp1[i];
        }
        return res;
    }
};