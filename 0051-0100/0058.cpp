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
    int lengthOfLastWord(string s) {
        for(;s[s.size() - 1] == ' ';)s.erase(s.end() - 1);
        if(0 == s.size())return 0;
        int a = 0;
        a = s.find_last_of(' ');
        return s.size() - a - 1;
    }
};

int main(){
    
    return 0;
}