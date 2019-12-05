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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL || (root->right == NULL && root->left == NULL))return root;
        return func(root->left, root->right);
    }
    bool func(TreeNode* l, TreeNode* r){
        if(l == NULL && r == NULL)return 1;
        if(l == NULL)return 0;
        if(r == NULL)return 0;
        if(l->val != r->val)return 0;
        return (func(l->right, r->left) && func(r->right, l->left));
    }
};

int main(){
    
    return 0;
}