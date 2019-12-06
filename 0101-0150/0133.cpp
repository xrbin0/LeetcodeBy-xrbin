#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    map <Node *, int> uni;
    int nNode;
    vector<Node*> self;
    vector <vector<Node*>> res;
    Node* cloneGraph(Node* node) {
        nNode = 0;
        tra(node);
        Node **r = new Node*[nNode];
        map <Node *, int> indexx;
        for(int i = 0;i < nNode;i++){
            r[i] = new Node();
            r[i]->val = self[i]->val;
            indexx[self[i]] = i;
        }
        for(int i = 0;i < nNode;i++){
            for(int j = 0;j < res[i].size();j++){
                r[i]->neighbors.push_back(r[indexx[res[i][j]]]);
            }
        }
        return r[0];
    }
    void tra(Node* node){
        if(uni[node] == 0x80000000) return;
        uni[node] = 0x80000000; nNode++;
        res.push_back(node->neighbors);
        self.push_back(node);
        int ssize = node->neighbors.size();
        for(int i = 0;i < ssize;i++) tra(node->neighbors[i]);
    }
};