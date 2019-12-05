#include "0000.h"

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* res = NULL;
        int size = nums.size();
        if(size == 0)return res;
        res = new TreeNode(0);
        queue <TreeNode *> tores;
        tores.push(res);
        int i = 1;
        while(i < size){
            TreeNode* temp = tores.front();
            tores.pop();
            temp->left = new TreeNode(0);
            temp->left->left = NULL;
            temp->left->right = NULL;
            tores.push(temp->left);i++;
            if(i == size)break;
            temp->right = new TreeNode(0);
            temp->right->left = NULL;
            temp->right->right = NULL;
            tores.push(temp->right);i++;
        }
        int ind = 0;
        inorder(nums, ind, res);
        return res;
    }
    void inorder(vector<int>& nums, int& ind, TreeNode *root){
        if(root == NULL)return;
        inorder(nums, ind, root->left);
        root->val = nums[ind++];
        inorder(nums, ind, root->right);
    }
};



// class Solution {
// public:
//     TreeNode* sortedArrayToBST(vector<int>& nums) {
//         TreeNode* res = NULL;
//         if(nums.size() == 0)return res;
//         int l = 0, r = 0, mid = (l + r)/2;
//         while(l <= r){
//             if(func(nums, mid, res) == 0){
//                 return res;
//             }else if(func(nums, mid, res) == 1){
//                 r = mid + 1;
//                 mid = (l + r)/2;
//             }else if(func(nums, mid, res) == -1){
//                 l = mid - 1;
//                 mid = (l + r)/2;
//             }
//         }
//         return res;
//     }
//     int func(vector<int>& nums, int ind, TreeNode*& res){

//     }
//     TreeNode* build(vector<int>& nums, int r, int l){
//         if(r == l){
//             TreeNode* node = new TreeNode(nums[r]);
//             node->left = NULL;
//             node->right = NULL;
//         }else{

//         }
//     }
// };