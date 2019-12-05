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
    int longestValidParentheses(string s) {
        int size = s.size();
        if(size == 1 || size == 0)return 0;

        int sums = 0;int res = 0;int rest = 0;

        for(int i = 0;i < size;i++){
            if(s[i] == '('){
                sums++;
            }
            else sums--;

            if(sums < 0){
                sums = 0;rest = 0;
            }else if(sums == 0){
                rest++;
                if(res < rest)res = rest;
            }
            else{
                rest++;
            }
        }

        int sums2 = 0, counts = 0, countstemp = 0;
        if(sums != 0){
            for(int i = size - 1;i >= (int)size - rest;i--){
                if(s[i] == ')'){
                    sums2++;
                }
                else sums2--;

                if(sums2 < 0){
                    sums2 = 0;
                    counts = 0;
                }
                else if(sums2 == 0){
                    counts++;
                    if(counts > countstemp)countstemp = counts;
                }
                else {
                    counts++;
                }
                
            }
        }
        
        if(res < countstemp)return countstemp;
        return res;
    }
};

int main(){
    Solution a;
    cout<<a.longestValidParentheses("()");
    return 0;
}