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
    int size;
public:
    void rotate(vector<vector<int>>& matrix) {
        size = matrix.size();
        vector <int>row;
        for(int i = 0;i < size / 2;i++){
            for(int j = i;j < size - 1 - i;j++){
                int r1 = i, c1 = j;
                rs1(r1, c1);
                int r2 = r1, c2 = c1;
                rs2(r2, c2);
                int r3 = r2, c3 = c2;
                rs1(r3, c3);
                // cout<<i<<" "<<j<<endl;
                // cout<<r1<<" "<<c1<<endl;
                // cout<<r2<<" "<<c2<<endl;
                // cout<<r3<<" "<<c3<<endl;
                int rem = matrix[i][j];
                matrix[i][j] = matrix[r3][c3];
                matrix[r3][c3] = matrix[r2][c2];
                matrix[r2][c2] = matrix[r1][c1];
                matrix[r1][c1] = rem;
            }
        }
    }

    void rs1(int &row, int &col){
        int temp = col;
        col = size - row - 1;
        row = temp;
    }
    void rs2(int &row, int &col){
        int temp = row;
        row = col;
        col = size - temp - 1;
    }

};

int main(){
    
    return 0;
}