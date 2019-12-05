#include "0000.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        func(root);
        return res;
    }
    void func(TreeNode* root){
        if(root == NULL)return;
        func(root->left);
        res.push_back(root->val);
        func(root->right);
    }
};