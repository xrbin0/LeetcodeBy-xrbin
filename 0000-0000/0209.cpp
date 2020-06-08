#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0, right = 0, sum = 0, res = 0x80000000, sizes = nums.size();
        while(right < sizes){
            sum += nums[right++];
            if(sum >= s){
                res = min(res, right - left);
                sum -= nums[left++];
            }
        }
        return res;
    }
};