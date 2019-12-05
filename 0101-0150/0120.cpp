#include "0000.h"

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {//down to up
        if(triangle.size() == 0)return 0;
        int size = triangle.size();
        for(int i = 1;i < size;i++){
            triangle[i][0] += triangle[i-1][0];
            for(int j = 1;j < i;j++){
                triangle[i][j] += min(triangle[i-1][j-1], triangle[i][j]);
            }
            triangle[i][i] += triangle[i-1][i-1];
        }
        int min = 0x7fffffff;
        for(int i = 0;i < size;i++){
            if(min > triangle[size- 1][i])min = triangle[size- 1][i];
        }
        return size;
    }
};