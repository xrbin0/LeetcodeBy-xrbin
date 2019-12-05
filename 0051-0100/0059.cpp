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
    vector<vector<int>> generateMatrix(int n) {
        if(n == 0)return {{}};
        vector<vector<int> > res(n,vector<int>(n,0));
        int ind = 1;
        for(int i = 0;i < (n + 1) / 2;i++){
            if(i == n - 1 - i){
                res[i][i] = ind;
                break;
            }
            for(int j = i;j < n - 1 - i;j++){
                res[i][j] = ind++;
            }
            for(int j = i;j < n - 1 - i;j++){
                res[j][n - 1 - i] = ind++;
            }
            for(int j = n - 1 - i;j > i;j--){
                res[n - 1 - i][j] = ind++;
            }
            for(int j = n - 1 - i;j > i;j--){
                res[j][i] = ind++;
            }
        }
        return res;
    }
};

int main(){
    
    return 0;
}