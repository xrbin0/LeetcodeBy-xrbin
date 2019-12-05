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
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)return 0;
        vector<int> a;
        vector<vector<int>> dp;
        for(int i = 0;i < matrix.size();i++){
            if(matrix[i][0] == '1')a.push_back(1);
            else a.push_back(0);//less before
            for(int j = 1;j < matrix[0].size();j++){
                int temp = 0;
                if(matrix[i][j] == '1')
                    temp = a[j - 1] + 1;
                a.push_back(temp);
            }
            dp.push_back(a);
            a.clear();
        }
        int res = 0;int min = 0;
        for(int i = 0;i < matrix.size();i++){
            for(int j = 0;j < matrix[0].size();j++){
                if(matrix[i][j] == '1'){
                    min = dp[i][j];
                    for(int k = i;k >= 0;k--){
                        if(dp[k][j] < min)min = dp[k][j];
                        if(min == 0)break;
                        if((i - k + 1) * min > res)res = (i - k + 1) * min;
                    }
                }
            }
        }
        return res;
        // for(int i = 0;i < matrix.size();i++){
        //     for(int j = 0;j < matrix[0].size();j++){
        //         cout<<dp[i][j]<<" ";
        //     }cout<<endl;
        // }
    }
};

int main(){
    Solution a;
    vector <vector<char> >b;
    vector <char> c;
    c.push_back('0');
    c.push_back('1');
    b.push_back(c);
    cout<<a.maximalRectangle(b);
    return 0;
}