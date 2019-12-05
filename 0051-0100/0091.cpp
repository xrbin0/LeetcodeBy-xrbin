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
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0)return 0;
        if(s.size() == 1)return 1;
        if(s == "0")return 0;
        vector<int> dp(s.size() + 1, 0);
        int i = 0;
        if(s[i+1] == '0'){
            dp[0] = 0;
            dp[1] = 1;
            i = 2;
        }else{
            dp[0] = 1;
            i = 1;
        }
        for(;i < s.size() - 1;i++){
            if(s[i+1] == '0'){
                dp[i] = dp[i-1];
                i++;
                dp[i] = dp[i-1];
            }else{
                if((s[i-1] == '1' || s[i-1] == '2') && s[i] <= '6' && s[i] >= '1'){
                    dp[i] = dp[i-1];
                    if(i > 1)dp[i]+=dp[i-2];
                    else dp[i] += 1;
                }else dp[i] = dp[i-1];
            }
        }
        if((s[i-1] == '1' || s[i-1] == '2') && s[i] <= '6' && s[i] >= '1'){
            // cout<<"win"<<endl;
            dp[i] = dp[i-1];
            if(i > 1)dp[i]+=dp[i-2];
            else dp[i] += 1;
        }else dp[i] = dp[i-1];
        return dp[i];
    }
};

int main(){
    
    return 0;
}