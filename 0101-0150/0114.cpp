#include "0000.h"

class Solution {
public:
    stack <TreeNode *> pre;
    void flatten(TreeNode* root) {
        if(!root)return;
        pre.push(root);
        TreeNode *temp = NULL;
        while(!pre.empty()){
            temp = pre.top();
            pre.pop();
            if(temp->right){
                pre.push(temp->right);
            }
            if(temp->left){
                pre.push(temp->left);
            }
            if(temp->right == NULL && temp->left == NULL && !pre.empty()){
                temp->right = pre.top();
                temp->left = NULL;
            }else if(temp->left != NULL)
                temp->right = temp->left;
            temp->left = NULL;
        }
    }
};