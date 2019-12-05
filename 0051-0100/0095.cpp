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
    vector<vector<TreeNode*> >process;
    vector<TreeNode*> pre;
    TreeNode* rem;
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)return {};
        pre.push_back(NULL);
        process.push_back(pre);
        pre.clear();
        for(int i = 1;i <= n;i++){
            for(int j = 0;j <= i - 1;j++){
                for(int k = 0;k < process[j].size();k++){
                    for(int l = 0;l < process[i - 1 - j].size();l++){
                        TreeNode *newnode = new TreeNode(j+1);
                        newnode->left = buildATree(process[j][k], 0);
                        newnode->right = buildATree(process[i-1-j][l], j+1);
                        pre.push_back(newnode);
                    }
                }
            }
            process.push_back(pre);
            pre.clear();
        }
        return process[n];
    }
    TreeNode* buildATree(TreeNode * root, int a){
        if(root == NULL)return root;
        TreeNode *newnode = new TreeNode(root->val + a);
        newnode->left = buildATree(root->left, a);
        newnode->right = buildATree(root->right, a);
        return newnode;
    }
};

void un(TreeNode *root){
    if(!root)return;
    un(root->left);
    cout<<root->val<<" ";
    un(root->right);
}

int main(){
    Solution a;
    vector<TreeNode*> te = a.generateTrees(3);
    for(int i = 0;i < 5;i++){
        un(te[i]);cout<<endl;
    }
    return 0;
}