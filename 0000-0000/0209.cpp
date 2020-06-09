#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int left = 0, right = 0, sum = 0, res = 0x7FFFFFFF, sizes = nums.size();
        while(left < sizes){
            // cout << left << " " << right << endl;
            if(right < sizes) sum += nums[right++];
            while(left < sizes && sum >= s){
                res = min(res, right - left);
                sum -= nums[left++];
            }
            if(right == sizes && sum < s) break;
        }
        if(res == 0x7FFFFFFF) res = 0;
        return res;
    }
};