#include "0000.h"


class Solution {
public:
    queue <Node *>tores;
    Node* connect(Node* root) {
        if(!root)return NULL;
        tores.push(root);
        int ind = 1;Node* temp;
        while(!tores.empty()){
            for(int i = 0;i < ind - 1;i++){
                temp = tores.front();
                tores.pop();
                if(temp->left){
                    tores.push(temp->left);
                    tores.push(temp->right);
                }
                temp->next = tores.front();
            }
            temp = tores.front();
            tores.pop();
            if(temp->left){
                tores.push(temp->left);
                tores.push(temp->right);
            }
            ind <<= 1;
        }
        return root;
    }
};