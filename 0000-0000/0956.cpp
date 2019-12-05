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
    int tallestBillboard(vector<int>& rods) {
        int size = rods.size();
        int **dp = new int*[size + 1];
        for(int i = 0;i < size + 1;i++){
            dp[i] = new int[5001];
            for(int j = 0;j < 5001;j++){
                dp[i][j] = -5001;
            }
        }
        int sm = 0;
        dp[0][0] = 0;
        for(int i = 1;i < size + 1;i++){
            sm += rods[i-1];
            for(int j = 0;j <= sm;j++){
                dp[i][j] = max(dp[i-1][j], dp[i][j]);
                if(j + rods[i-1] <= sm)
                    dp[i][j+rods[i-1]] = max(dp[i-1][j], dp[i][j+rods[i-1]]);
                dp[i][abs(j-rods[i-1])] = \
                max(dp[i][abs(j-rods[i-1])], dp[i-1][j] + min(j,rods[i-1]));
            }
        }
        return dp[size][0];
    }
};

int main(){
    
    return 0;
}