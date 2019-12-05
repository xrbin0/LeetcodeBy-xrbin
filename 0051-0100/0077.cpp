#include "0000.h"


class Solution {
public:
    vector<vector<int>> res;
    vector<int> ares;
    vector<int> nums;
    int n1, k1;int counts;
    vector<vector<int>> combine(int n, int k) {
        n1 = n, k1 = k;counts=0;
        for(int i = 0;i < n;i++){
            nums.push_back(i + 1);
        }
        func(0);
        return res;
    }
    void func(int ind){
        if(counts == k1){
            res.push_back(ares);
            return;
        }
        for(int i = ind;i < nums.size();i++){
            ares.push_back(nums[i]);
            counts++;
            func(1+i);
            counts--;
            ares.pop_back();
        }
    }
};