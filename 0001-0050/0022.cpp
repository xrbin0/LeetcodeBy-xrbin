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
    vector<string> res;
    string ares;
    int las = 0, l = 0, r = 0;
public:
    vector<string> generateParenthesis(int n) {
        las = n;
        dfs(0);
        return res;
    }
    void dfs(int ind){
        if(las == ind){
            res.push_back(ares);
        }
        if(l < las){
            ares.push_back('(');
            l++;
            r++;
            dfs(ind + 1);
            l--;
            r--;
            ares.pop_back();
        }
        if(r > 0){
            ares.push_back(')');
            l--;
            dfs(ind + 1);
            l++;
            ares.pop_back();
        }
    }
};

int main(){
    
    return 0;
}