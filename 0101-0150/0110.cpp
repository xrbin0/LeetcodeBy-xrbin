#include "0000.h"

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL)return 1;
        heights(root);
        res = 1;
        return res;
    }
    bool res;
    int heights(TreeNode *root){
        if(!res)return 0;
        if(root == NULL)return 1;
        root->val = max(heights(root->right), heights(root->left)) + 1;
        if(abs(heights(root->right) - heights(root->left)) > 1)res = 0;
        return root->val;
    }
};