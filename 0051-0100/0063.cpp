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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int sizerow = obstacleGrid.size();
        int sizecol = obstacleGrid[0].size();
        vector<long long int> dp(sizecol+3,0);
        for(int i = 0;i < sizecol;i++){
            if(obstacleGrid[0][i] == 0)
                dp[i] = 1;
            else break;
        }
        for(int i = 1;i < sizerow;i++){
            if(obstacleGrid[i][0] != 0){
                dp[0] = 0;
            }
            for(int j = 1;j < sizecol;j++){
                if(obstacleGrid[i][j] == 0){
                    long long int temp = 0;
                    if(obstacleGrid[i-1][j] == 0){
                        temp+=dp[j];
                    }
                    if(obstacleGrid[i][j-1] == 0){
                        temp+=dp[j-1];
                    }
                    dp[j] = temp;
                }else{
                    dp[j] = 0;
                }
            }
        }
        return dp[sizecol - 1];
    }
};


int main(){
    
    return 0;
}