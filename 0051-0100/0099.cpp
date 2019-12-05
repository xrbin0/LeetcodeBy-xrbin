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
    int pre = 0x80000000;
    int reverse = 0;int count1 = 0, count2 = 0;
    int count3 = 0;
    int rem1 = 0, rem2 = 0;
    void recoverTree(TreeNode* root) {
        func1(root);
        if(reverse == 1){
            func2(root);
            count3 = 0;
            func3(root);
        }else if(reverse == 2){
            // cout<<2<<endl;
            func4(root);
            count3 = 0;
            func5(root);
            // cout<<rem1<<" "<<rem2<<endl;
        }
    }
    void func1(TreeNode *root){
        if(root == NULL)return;
        func1(root->left);
        if(reverse != 2)count2++;
        if(root->val < pre)reverse++;
        if(reverse == 0)count1++;
        pre = root->val;
        func1(root->right);
    }
    void func2(TreeNode *root){
        if(root == NULL)return;
        func2(root->left);

        count3++;
        if(count3 == count1){
            rem1 = root->val;
        }
        if(count3 == count1 + 1){
            rem2 = root->val;
        }
        
        func2(root->right);
    }
    void func3(TreeNode *root){
        if(root == NULL)return;
        func3(root->left);

        count3++;
        if(count3 == count1){
            root->val = rem2;
        }
        if(count3 == count1 + 1){
            root->val = rem1;
        }

        func3(root->right);
    }
    void func4(TreeNode *root){
        if(root == NULL)return;
        func2(root->left);

        count3++;
        if(count3 == count1){
            rem1 = root->val;
        }
        if(count3 == count2){
            rem2 = root->val;
        }
        
        func2(root->right);
    }
    void func5(TreeNode *root){
        if(root == NULL)return;
        func3(root->left);

        count3++;
        if(count3 == count1){
            root->val = rem2;
        }
        if(count3 == count2){
            root->val = rem1;
        }

        func3(root->right);
    }
};

int main(){
    
    return 0;
}