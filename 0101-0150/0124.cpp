#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int main(){
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(5);
    n1->left = n2;
    n2->left = n3;
    n3->left = n4;
    n4->left = n5;
    Solution a;
    cout<<a.maxPathSum(n1);

    return 0;
}

// class Solution {
// public:
//     int res = 0x80000000;
//     int maxPathSum(TreeNode* root) {
//         TreeNode *replica = copyAtree(root);
//         subTraversal1(root, replica);
//         subTraversal3(root, replica);
//         return res;
//     }
//     TreeNode *copyAtree(TreeNode *root){
//         if(root == NULL)return NULL;
//         TreeNode *node = new TreeNode(root->val);
//         node->left = copyAtree(root->left);
//         node->right = copyAtree(root->right);
//         return node;
//     }
//     void subTraversal1(TreeNode* root, TreeNode* replica){
//         if(root == NULL)return;
//         subTraversal1(root->left, replica->left);
//         subTraversal1(root->right, replica->right);

//         int r = 0, l = 0;
//         if(root->left != NULL)l = replica->left->val;
//         if(root->right != NULL)r = replica->right->val;
//         int max = r > l? r : l;
//         if(0 < max){
//             replica->val += max;
//         }
//     }
//     void subTraversal3(TreeNode* root, TreeNode* replica){
//         if(root == NULL)return;
//         // cout<<root->val<<" ";
//         // cout<<replica->val<<endl;
//         subTraversal3(root->left, replica->left);
//         subTraversal3(root->right, replica->right);
//         int max = root->val;
//         if(root->left != NULL && replica->left->val > 0)max += replica->left->val;
//         if(root->right != NULL && replica->right->val > 0)max += replica->right->val;
//         if(max > res)res = max;
//     }
// };