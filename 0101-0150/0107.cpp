#include "0000.h"
class Solution {
public:
    queue <TreeNode*> tores;
    int maxs = 0;
    int maxDepth(TreeNode* root) {
        func(root, 0);
        return maxs;
    }
    void func(TreeNode* root, int ind){
        if(ind > maxs)maxs = ind;
        if(root == NULL)return;
        func(root->left, ind + 1);
        func(root->right, ind + 1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)return {{}};
        func(root, 0);
        vector<vector<int>> res(maxs, vector<int>(0,0));
        tores.push(root);
        int nums1 = 1;
        int nums2 = 0;
        maxs--;
        while(!(nums1 == 0 && nums2 == 0) && !tores.empty()){
            for(;nums1 > 0;nums1--){
                TreeNode* temp = tores.front();
                res[maxs].push_back(temp->val);
                if(temp->left){
                    tores.push(temp->left);nums2++;
                }
                if(temp->right){
                    tores.push(temp->right);nums2++;
                }
            }
            nums1 = nums2;
            nums2 = 0;
        }
        return res;
    }
};

int main(){
    freopen64("test","w",stdout);
    for(int i = i;i <= 202;i++){
        cout<<"\t./parser ../Tests/"<<i<<".cmm"<<endl;
    }
}