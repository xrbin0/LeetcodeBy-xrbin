#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <algorithm>
using namespace std;



class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> vine;
        if(nums.size() == 1){
            vine.push_back(nums);
            return vine;
        }
        for(int i = 0;i < nums.size();i++){
            vector<int>::iterator cur = nums.begin() + i;
            int temp = *cur;
            nums.erase(cur);
            vector<vector<int>> res = permute(nums);
            vector <int> pre;
            while(!res.empty()){
                res[0].insert(res[0].begin(), temp);
                vine.push_back(res[0]);
                res.erase(res.begin());
            }
            nums.insert(cur, temp);
        }
    }
};


int main(){
    Solution a;
    vector<int> b;
    b.push_back(1);
    b.push_back(2);
    b.push_back(3);
    vector<vector<int>> res = a.permute(b);
    for(int i = 0;i < res.size();i++){
        for(int j = 0;j < res[0].size();j++){
            cout<<res[i][j]<<" ";
        }cout<<endl;
    }

    return 0;
}