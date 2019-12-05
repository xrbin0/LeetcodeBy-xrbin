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
    string ares;
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        int ind = 0;
        for(int i = 1;i <= 3;i++){
            if(isValid(s, ind, ind + i))
            for(int j = 1;j <= 3;j++){
                if(isValid(s, ind + i, ind + i + j))
                for(int k = 1;k <= 3;k++){
                    if(isValid(s, ind + i + j, ind + i + j + k))
                    for(int l = 1;l <= 3;l++){
                        if(isValid(s, ind + i + j, s.size())){
                            ares = s;
                            ares.insert(ares.begin() + i, '.');
                            ares.insert(ares.begin() + i + j + 1, '.');
                            ares.insert(ares.begin() + i + j + k + 1, '.');
                            res.push_back(ares);
                            ares.clear();
                        }
                    }
                }
            }
        }
        return res;
    }
    bool isValid(string& s,int begin, int end){
        if(end >= s.size())return 0;
        string temp(s, begin, end - begin);
        if(atoi(temp.c_str()) < 255)return 1;
        return 0;
    }
};

int main(){
    
    return 0;
}