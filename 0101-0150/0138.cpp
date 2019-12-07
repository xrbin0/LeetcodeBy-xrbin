#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        int num_node = 0;
        Node* temp = head;
        while(temp != NULL){
            num_node++;
            temp = temp->next;
        }
        temp = head;
        Node **res = new Node*[num_node + 1];
        map <Node*, int> unio;
        res[0] = new Node;
        for(int i = 0;i < num_node;i++){
            unio[temp] = i;
            res[i + 1] = new Node;
            res[i]->next = res[i + 1];
            res[i]->val = temp->val;
            temp = temp->next;
        }
        temp = head;
        res[num_node - 1]->next = NULL;
        for(int i = 0;i < num_node;i++){
            if(temp->random == NULL) 
              res[i]->random = NULL;
            else 
              res[i]->random = res[unio[temp->random]];
            temp = temp->next;
        }

        return res[0];
    }
};