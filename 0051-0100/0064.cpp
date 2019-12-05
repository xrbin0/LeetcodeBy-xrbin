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
public:
    int minPathSum(vector<vector<int>>& grid) {
        int sizerow = grid.size();
        int sizecol = grid[0].size();
        vector<int> dp(sizecol+3, 0);
        dp[0] = grid[0][0];
        for(int i = 1;i < sizecol;i++){
            dp[i] = grid[0][i] + dp[i-1];
        }
    for(int i = 1;i < sizerow;i++){
        dp[0] += grid[i][0];
            for(int j = 1;j < sizecol;j++){
                dp[j] = grid[i][j] + (dp[j - 1] < dp[j] ? dp[j - 1] : dp[j]);
            }
        }
        return dp[sizecol - 1];
    }
};


int main(){
    
    return 0;
}