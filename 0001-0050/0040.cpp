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
    vector<vector<int> > res;
    vector<int> ares;
    int n;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = target;
        if(candidates.size() == 0)return res;
        sort(candidates.begin(),candidates.end());
        func(candidates, 0);
        return res;
    }
    void func(vector<int>& candidates, int ind){
        if(n == 0){
            res.push_back(ares);
            return;
        }
        if(ind >= candidates.size())return;
        func(candidates, ind+1);
        if(n < candidates[ind])return;
        
        // if(ind > 0 && candidates[ind - 1] == candidates[ind])return;
        if(ind > 0 && candidates[ind - 1] == candidates[ind]){
            int count1 = 0;
            for(int i = 0;i < ind && candidates[ind - 1 - i] == candidates[ind-i];i++)count1++;
            int count2 = 0;
            for(int i = ares.size() - 1;i > 0 && ares[i] == ares[i-1];i--)count2++;
            if(ares.size() == 0 || (ares[ares.size()-1] == candidates[ind] && count1 == count2)){
                n -= candidates[ind];
                ares.push_back(candidates[ind]);
                func(candidates, ind+1);
                ares.pop_back();
                n += candidates[ind];
            }
        }else{
            n -= candidates[ind];
                ares.push_back(candidates[ind]);
                func(candidates, ind+1);
                ares.pop_back();
                n += candidates[ind];
        }
    }
};


int main(){
    
    return 0;
}