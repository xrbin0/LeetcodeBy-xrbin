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
    vector<vector<int>> res;
    vector<int> nu;
    vector<int> ares;
    int size;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        nu = nums;size = nums.size();
        if(nums.size() == 0)return res;
        if(nums.size() == 1){
            res.push_back(nums);
            return res;
        }
        sort(nu.begin(), nu.end());
        dfs(0);
        return res;
    }
    void dfs(int ind){
        if(ind == size){
            res.push_back(ares);
            return;
        }
        for(int i = 0;i < nu.size();i){
            ares.push_back(nu[i]);
            nu.erase(nu.begin() + i);
            dfs(ind + 1);
            nu.insert(nu.begin() + i, ares[ares.size()-1]);
            ares.pop_back();
            for(i++;i < nu.size() && nu[i] == nu[i - 1];i++);
        }
    }
};


int main(){
    
    return 0;
}