#include "0000.h"

class Solution {
public:
    int cur = 0x80000000;bool flags = 1;
    bool isValidBST(TreeNode* root) {
        if(root == NULL)return 1;
        bool flag = isValidBST(root->left);
        if(flags && cur == 0x80000000 && root->val == cur){
            flags = 0;flag = 1;
        }
        else if(cur >= root->val)return 0;
        cur = root->val;
        flag &= isValidBST(root->right);
        return flag;
    }
};