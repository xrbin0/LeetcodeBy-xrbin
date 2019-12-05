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
    vector<string> res;
    vector<string> alph;
    int size = 0;
    vector<string> letterCombinations(string digits) {
        alph.push_back("0");
        alph.push_back("1");
        alph.push_back("abc");
        alph.push_back("def");
        alph.push_back("ghi");
        alph.push_back("jkl");
        alph.push_back("mno");
        alph.push_back("pqrs");
        alph.push_back("tuv");
        alph.push_back("wxyz");
        size = digits.size();
        if(digits.size() == 0)return res;
        string aares = "";
        dfs(digits, aares, 0);
    }
    void dfs(string s, string& aares, int ind){
        if(ind == size){
            res.push_back(aares);
            return;
        }
        int nums = s[ind] - '0';
        for(int i = 0;i < alph[nums].size();i++){
            aares.push_back(alph[nums][i]);
            dfs(s, aares, ind + 1);
            aares.pop_back();
        }
        return;
    }
};

int main(){
    
    return 0;
}