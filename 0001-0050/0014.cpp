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
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)return "";
        if(strs.size() == 1)return strs[0];
        int minLength = 0x7FFFFFFF;
        for(int i = 0;i < strs.size();i++){
            if(strs[i].length() < minLength)minLength = strs[i].length();
        }
        string res = "";
        for(int k = 0;k < minLength;k++){
            for(int i = 0;i < strs.size() - 1;i++){
                if(strs[i][k] != strs[1 + i][k])return res;
            }
            res.push_back(strs[0][k]);
        }
        return res;
    }
};



int main(){
    

    return 0;
}