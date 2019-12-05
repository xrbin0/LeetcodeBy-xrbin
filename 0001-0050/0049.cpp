#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>
#include <stdio.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    struct node{
        string str;
        int ind;
    };
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<node> anew;
        int size = strs.size();
        for(int i = 0;i < size;i++){
            node temp;temp.str = strs[i];temp.ind = i;
            sort(temp.str.begin(), temp.str.end());
            anew.push_back(temp);
        }
        sort(anew.begin(), anew.end(), this->cmp);
        vector<vector<string>> res;
        vector<string> ares;
        for(int i = 0;i < size;){
            ares.push_back(strs[anew[i].ind]);
            int j = i + 1;
            for(;j < size && anew[j].str == anew[i].str;j++){
                ares.push_back(strs[anew[j].ind]);
            }
            i = j;
            res.push_back(ares);
            ares.clear();
        }
        return res;
    }
    static bool cmp(node &a1, node &a2){
        return strcmp(a1.str.c_str(), a2.str.c_str()) < 0;
    }
};


int main(){
    
    return 0;
}