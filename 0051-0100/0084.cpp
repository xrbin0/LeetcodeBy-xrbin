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
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        vector <int>res = heights;
        int max = 0;int c = 0;
        for(int i = 2;i <= size;i++){
            for(int j = 0;j < size - c - 1;j++){
                res[j] = min(res[j], res[j+1]);
                if(res[j] * (c + 2) > max)max = (c + 2) * res[j];
            }
            c++;
        }
        return max;
    }
};

int main(){
    
    return 0;
}