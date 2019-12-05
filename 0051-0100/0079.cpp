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
    int sizerow = 0, sizecol = 0;
    vector<vector<bool>> flag;
    vector<vector<bool>> flagr;
    bool res;
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size() == 0)return 1;
        sizerow = board.size();
        if(sizerow == 0)return 0;
        sizecol = board[0].size();
        if(sizecol == 0)return 0;
        vector<vector<bool>> a(sizerow, vector<bool>(sizecol, 0));

        for(int i = 0;i < sizerow;i++)
        for(int j = 0;j < sizecol;j++){
            if(!res && word[0] == board[i][j]){
                dfs(a, board, word, i, j, 1);
            }
        }

        return res;
    }
    void dfs(vector<vector<bool>> a, vector<vector<char>>& board, string &word, int i, int j, int ind){
        if(res)return;
        if(ind == word.size())res = 1;
        if(!res && i > 0 && word[ind] == board[i-1][j]){
            dfs(a, board, word, i-1, j, ind+1);
        }
        if(!res && j > 0 && word[ind] == board[i][j-1]){
            dfs(a, board, word, i, j-1, ind+1);
        }
        if(!res && i < sizerow - 1 && word[ind] == board[i+1][j]){
            dfs(a, board, word, i+1, j, ind+1);
        }
        if(!res && j < sizecol - 1 && word[ind] == board[i][j+1]){
            dfs(a, board, word, i, j+1, ind+1);
        }
    }
};

int main(){
    
    return 0;
}