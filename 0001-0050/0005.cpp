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
    string longestPalindrome(string s) {
        if(s.size() == 0 || s.size() == 1)return s;
        if(s.size() == 2){
            if(s[0] == s[1]){
                return s;
            }else{
                string s1(s,1,1);
                return s1;
            }
        }
        string res;
        int right = 0, left = 0;
        int maxLength = 0;
        for(int i = 0; i < s.size(); i++){
            right = i, left = i;
            for(int j = 0;right + j < s.size() && left - j >= 0;j++){
                if(s[right + j] != s[left - j]){
                    if(maxLength <= 2 * j - 1){
                        maxLength = 2 * j - 1;
                        res.assign(s, left - j + 1, maxLength);
                        // cout<<i<<" "<<j<<endl;
                        // cout<<res<<endl;
                    }
                    break;
                }
                if((right + j == s.size() - 1 || left - j == 0) && s[right + j] == s[left - j]){
                    if(maxLength <= 2 * j + 1){
                        maxLength = 2 * j + 1;
                        res.assign(s, left - j, maxLength);
                        // cout<<res<<endl;
                    }
                    break;
                }
            }
        }
        for(int i = 0; i < s.size() - 1; i++){
            right = i + 1, left = i;
            if(s[right] != s[left])continue;
            for(int j = 0;right + j < s.size() && left - j >= 0;j++){
                if(s[right + j] != s[left - j]){
                    if(maxLength <= 2 * j){
                        maxLength = 2 * j;
                        res.assign(s, left - j + 1, maxLength);
                    }
                    break;
                }
                if((right + j == s.size() - 1 || left - j == 0) && s[right + j] == s[left - j]){
                    if(maxLength <= 2 * j + 2){
                        maxLength = 2 * j + 2;
                        res.assign(s, left - j, maxLength);
                    }
                    break;
                }
            }
        }
        return res;
    }
};

int main(){

    Solution a;
    cout << a.longestPalindrome((string)"abadd");

    return 0;
}