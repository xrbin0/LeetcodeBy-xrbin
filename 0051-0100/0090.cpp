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
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<vector<int>> res;
    vector<int> ares;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)return res;
        sort(nums.begin(), nums.end());
        res.push_back(ares);
        ares.push_back(nums[0]);
        res.push_back(ares);
        ares.pop_back();
        // for(int i = 1;i < size;i++){
        //     if(nums[i] != nums[i - 1]){
        //         ares.push_back(nums[i]);
        //         res.push_back(ares);
        //         ares.pop_back();
        //     }
        // }
        int l = 1, countsize = 0;
        for(int i = 1;i < size;i++){
            if(nums[i] == nums[i-1]){
                for(int j = l;j < size;j++){
                    res[j].push_back(nums[i]);
                    res.push_back(res[j]);
                    res[j].pop_back();
                    countsize++;
                }
                l = size;
                size += countsize;
                countsize = 0;
            }else{
                for(int j = 0;j < size;j++){
                    res[j].push_back(nums[i]);
                    res.push_back(res[j]);
                    res[j].pop_back();
                    countsize++;
                }
            }
        }
        return res;
    }
};

int main(){
    
    return 0;
}