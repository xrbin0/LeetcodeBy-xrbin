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

class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 0)return {0};
        vector<int> res = {0, 1};
        int size = 2;
        for(int i = 1;i < n;i++){
            for(int j = 0;j < size;j++){
                res[j] <<= 1;
            }
            for(int j = size - 1;j >= 0;j--){
                res.push_back(res[j] + 1);
            }
            size <<= 1;
        }
        // for(int i = 0;i < size;i++){
        //     printf("%x ",res[i]);
        // }
        return res;
    }
};

int main(){
    
    return 0;
}