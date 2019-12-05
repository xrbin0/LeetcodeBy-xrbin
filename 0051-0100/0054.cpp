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
    vector <int> res;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        func(matrix, 0, matrix.size(), 0, matrix[0].size());
        return res;
    }
    void func(vector<vector<int>>& matrix, int row1, int row2, int col1, int col2){
        if(row1 > row2 || col1 > col2)return;
        for(int i = col1;i < col2;i++)
            res.push_back(matrix[row1][i]);
        for(int i = row1;i < row2;i++)
            res.push_back(matrix[i][col1]);
        for(int i = col2;i < col1;i--)
            res.push_back(matrix[row2][i]);
        for(int i = row2;i > row1;i--)
            res.push_back(matrix[i][col2]);
        func(matrix, row1 + 1, row2 - 1, col1 + 1, col2 - 1);
    }
};

int main(){
    
    return 0;
}