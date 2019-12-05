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
    vector<vector<int> > res;
    vector<int> ares;
    int n;
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        n = target;
        if(candidates.size() == 0)return res;
        sort(candidates.begin(),candidates.end(),cmp);
        func(candidates, 0);
        return res;
    }
    void func(vector<int>& candidates, int ind){
        if(ind == candidates.size())return;
            for(int j = 0;;j++){

                if(n < j * candidates[ind])break;
                else if(n == j * candidates[ind]){
                    for(int l = 0;l < j;l++)ares.push_back(candidates[ind]);
                    res.push_back(ares);
                    for(int l = 0;l < j;l++)ares.pop_back();
                    break;
                }

                n -= j * candidates[ind];
                for(int l = 0;l < j;l++)ares.push_back(candidates[ind]);
                func(candidates, ind+1);
                for(int l = 0;l < j;l++)ares.pop_back();
                n += j * candidates[ind];
                
            }
    }
    static bool cmp(int a ,int b){
        return a > b;
    }
};


int main(){
    
    return 0;
}