#include "0000.h"

class Solution {
public:
    int sumz;
    vector<int>ares;
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == NULL)return {};
        sumz = sum;
        func(root, 0);
        return res;
    }
    void func(TreeNode* root, int sums){
        if(!root)return;
        ares.push_back(root->val);
        sums += root->val;
        if(!root->left && !root->right && sums == sumz){
            res.push_back(ares);
        }
        func(root->left, sums);
        func(root->right, sums);
        ares.pop_back();
    }
};