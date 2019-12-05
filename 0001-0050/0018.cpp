#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>
#include <stdio.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int size = nums.size();
        if(size < 4)return res;
        sort(nums.begin(), nums.end());
        int ind1 = 0;
        int ind2 = 1;
        int ind3 = 2;
        int ind4 = size - 1;
        for(;ind1 < size - 3;){
            ind2 = ind1 + 1;
            target -= nums[ind1];
            for(;ind2 < size - 2;){
                target -= nums[ind2];
                ind3 = ind2 + 1;
                ind4 = size - 1;
                while(ind3 < ind4){
                    if(nums[ind3] + nums[ind4] == target){
                        vector <int> temp;
                        temp.push_back(nums[ind1]);
                        temp.push_back(nums[ind2]);
                        temp.push_back(nums[ind3]);
                        temp.push_back(nums[ind4]);
                        res.push_back(temp);
                        for(ind3++;ind3 < ind4 && nums[ind3] == nums[ind3-1];ind3++);//Pay attention to these words
                        for(ind4--;ind3 < ind4 && nums[ind4] == nums[ind4+1];ind4--);//Pay attention to these words
                    }else if(nums[ind3] + nums[ind4] > target){
                        ind4--;
                    }else ind3++;
                }
                target += nums[ind2];
                for(ind2++;ind2 < size - 2 && nums[ind2] == nums[ind2-1];ind2++);//Pay attention to these words
            }
            target += nums[ind1];
            for(ind1++;ind1 < size - 3 && nums[ind1] == nums[ind1-1];ind1++);//Pay attention to these words
        }
        return res;
    }
};


int main(){
    string a = "123456789";
    a.erase(a.begin() + 3, a.begin() + 6);
    cout<<a<<endl;
    return 0;
}