#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> oneResult;
        int ssize = s.size();
        if(ssize == 0) return {{}};
        if(ssize == 1) return {{s}};
        dfs(s, 0, result, oneResult);
        return result;
    }
    void dfs(const string& s, int first, \
      vector<vector<string>>& result, vector<string>& oneResult){
        int ssize = s.size();
        if(first >= s.size()){
            result.push_back(oneResult);
            return;
        }
        for(int i = 1;i <= ssize - first;i++){
            // string str(s, first, i); //这样会开销很大
            if(isPalindrome(s, first, first + i - 1)){
                // cout << string(s, first, i) << endl;
                oneResult.push_back(string(s, first, i));
                dfs(s, first + i, result, oneResult);
                oneResult.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int begins, int ends){
        while(begins < ends){
            // cout << begins << " " << ends << endl;
            if(s[begins] != s[ends]) return false;
            begins++; ends--;
        }
        return true;
    }
};