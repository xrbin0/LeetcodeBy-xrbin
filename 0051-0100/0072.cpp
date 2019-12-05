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
    int minDistance(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        if(size1 == 0)return size2;
        if(size2 == 0)return size1;
        vector<vector<int> > dp(size1, vector<int>(size2, 0));
        dp[0][0] = !(word1[0] == word2[0]);
        for(int i = 1;i < size2;i++){
            if(word2[i] == word1[0]){
                dp[0][i] = dp[0][i-1];
                for(i++;i < size2;i++)dp[0][i] = dp[0][i-1] + 1;
            }else dp[0][i] = dp[0][i-1] + 1;
        }
        for(int i = 1;i < size1;i++){
            if(word1[i] == word2[0]){
                dp[i][0] = dp[i-1][0];
                for(i++;i < size1;i++)dp[i][0] = dp[i-1][0] + 1;
            }else dp[i][0] = dp[i-1][0] + 1;
        }
        for(int i = 1;i < size1;i++){
            for(int j = 1;j < size2;j++){
                if(word1[i] == word2[j]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]) + 1;
                }
            }
        }
        
        // for(int i = 0;i < size1;i++){
        //     for(int j = 0;j < size2;j++){
        //         cout<<dp[i][j]<<" ";
        //     }cout<<endl;
        // }
        return dp[size1 - 1][size2 - 1];
    }
};

int main(){
    
    return 0;
}