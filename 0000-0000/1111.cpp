#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res;
        int last = 1;
        for(int i=0;i<seq.size();++i){
            char ch=seq[i];
            if(ch=='('){
                res.push_back(1-last);
                last=1-last;
            }
            else{
                res.push_back(last);
                last=1-last;
            }
        }
        return res;
    }
};



int main(){

    

    return 0;
}