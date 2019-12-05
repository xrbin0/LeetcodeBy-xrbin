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
public://不一定是前面两个字符匹配，仅仅一个就够了
    int size1, size2; 
    bool isInterleave(string s1, string s2, string s3) {
        size1 = s1.size();
        size2 = s2.size();
        if(size1 + size2 != s3.size())return 0;
        if(size1 == 0){
            if(s2 == s3)return 1;
            else return 0;
        }
        if(size2 == 0){
            if(s1 == s3)return 1;
            else return 0;
        }
        vector <vector<bool> >dp(size1 + 1, vector<bool>(size2 + 1, 0));
        dp[0][0] = 1;
        for(int i = 1;i < size1 + 1;i++){
            if(s1[i-1] == s3[i-1])dp[i][0] = 1;
            else break;
        }
        for(int i = 1;i < size2 + 1;i++){
            if(s2[i-1] == s3[i-1])dp[0][i] = 1;
            else break;
        }
        for(int i = 1;i < size1 + 1;i++){
            for(int j = 1;j < size2 + 1;j++){
                dp[i][j] = ((s1[i-1] == s3[i+j-1]) && dp[i-1][j]);
                if(!dp[i][j])dp[i][j] = ((s2[j-1] == s3[i+j-1]) && dp[i][j-1]);
            }
        }
        for(int i = 0;i < size1;i++){
            for(int j = 0;j < size2;j++){
                cout<<dp[i][j]<<" ";
            }cout<<endl;
        }
        return dp[size1][size2];
    }
};


int main(){
    
    return 0;
}