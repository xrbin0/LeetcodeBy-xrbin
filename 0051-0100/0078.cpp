#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include<list>
#include <stack>
#include <stdio.h>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> res;
    vector<int> ares;
    int n1, k1;
    int counts;
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        for(int i = 0;i <= size;i++){
            combine(nums, size, i);
        }
        return res;
    }
    void combine(vector<int>& nums, int n, int k) {
        n1 = n, k1 = k;counts=0;
        func(nums, 0);
    }
    void func(vector<int>& nums, int ind){
        if(counts == k1){
            res.push_back(ares);
            return;
        }
        for(int i = ind;i < nums.size();i++){
            ares.push_back(nums[i]);
            counts++;
            func(nums, 1+i);
            counts--;
            ares.pop_back();
        }
    }
};

int main(){
    
    return 0;
}