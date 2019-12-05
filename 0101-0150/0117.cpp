#include "0000.h"

class Solution {
public:
    queue <Node *>tores;
    Node* connect(Node* root) {
        if(!root)return NULL;
        tores.push(root);
        Node* temp = NULL;
        int ind1 = 1, ind2 = 0;
        while(!tores.empty()){
            for(int i = 0;i < ind1 - 1;i++){
                temp = tores.front();
                tores.pop();
                if(temp->left){
                    tores.push(temp->left);
                    ind2++;
                }
                if(temp->right){
                    tores.push(temp->right);
                    ind2++;
                }
                temp->next = tores.front();
            }
            temp = tores.front();
            tores.pop();
            if(temp->left){
                tores.push(temp->left);
                ind2++;
            }
            if(temp->right){
                tores.push(temp->right);
                ind2++;
            }
            ind1 = ind2;
            ind2 = 0;
        }
        return root;
    }
};