#include <bits/stdc++.h>
using namespace std;

class Solution {
public: //这题可以dp
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.size() == 0) return true;
        if(wordDict.size() == 0) return false;
        int ssize = s.size();
        for(int i = 1;i < ssize;i++){
            if(isInDict(s.substr(0, i), wordDict) && \
                wordBreak(string(s, i, ssize - i), wordDict)) return true;
        }
        return false;
    }
    bool isInDict(string s, vector<string>& wordDict){
        int ssize = wordDict.size(); int sSize = s.size();
        for(int i = 0;i < ssize;i++){
            if(sSize == wordDict[i].size() && s == wordDict[i]) return true;
        }
        return false;
    }
};