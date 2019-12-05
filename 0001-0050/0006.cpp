
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
    string convert(string s, int numRows) {
        if(s.size() == 0 || numRows == 1)return s;
        int period = 2 * numRows - 2;
        string res;

        //first row
        for(int i = 0;i < s.size();i+=period){
            res.push_back(s[i]);
        }
        //second row until last second row
        for(int j = 1;j < numRows - 1;j++){
            for(int i = j;i < s.size();i+=period){
                res.push_back(s[i]);
                if(i/period*period + period - j < s.size())
                    res.push_back(s[i/period*period + period - j]);
            }
        }
        for(int i = numRows - 1;i < s.size();i+=period){
            res.push_back(s[i]);
        }
        return res;
    }
};


int main(){
    Solution a;
    cout<<a.convert((string)"LEETCODEISHIRING", 3)<<endl;
    

    return 0;
}