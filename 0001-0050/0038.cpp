#include "0000.h"

class Solution {
public:
    string countAndSay(int n) {
        string res(to_string(1));
        string temp(res);
        for(int i = 1;i < n;i++){
            // cout<<res<<endl;
            res.clear();
            for(int j = 0;j < temp.size();){
                int ind1 = j;
                for(;ind1 + 1 < temp.size() && temp[ind1] == temp[ind1+1];ind1++);
                res += to_string(ind1-j+1);
                res += temp[j];
                j = ind1 + 1;
            }
            temp = res;
        }
        return res;
    }
};