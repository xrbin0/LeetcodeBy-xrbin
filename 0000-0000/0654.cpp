
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.empty())return NULL;
        // cout<<nums.size()<<endl;
        TreeNode* res = solve(nums, 0, nums.size() - 1);
        // cout<<res->val<<endl;
        // pri(res);
        return res;
    }
    TreeNode* solve(vector<int>& nums, int first, int last){
        // cout<<first<<" "<<last<<endl;
        if(first > last)return NULL;
        int maxs = -10000, maxIndex = 0;
        // cout<<maxs<<endl;
        for(int i = first;i <= last;i++){
            if(nums[i] > maxs){
                maxs = nums[i];
                maxIndex = i;
            }
        }
        TreeNode *root = new TreeNode((int)1);
        root->val = maxs;
        root->left = NULL;
        root->right = NULL;
        root->left = solve(nums, first, maxIndex - 1);
        root->right = solve(nums, maxIndex + 1, last);

        // cout<<first<<" "<<last<<endl;
        return root;
    }
    void pri(TreeNode *root){
        if(!root)return;
        printf("%d ", root->val);
        pri(root->left);
        pri(root->right);
        
    }

};




int main(){
    Solution a;
    // vector

    return 0;
}