#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack <char> a;
        int size = s.size();
        for(int i = 0;i < size;i++){
            if(s[i] == '('){
                a.push('(');
            }else if(s[i] == ')'){
                if(a.top() == '(')a.pop();
                else return false;
            }else if(s[i] == '['){
                a.push('[');
            }else if(s[i] == ']'){
                if(a.top() == '[')a.pop();
                else return false;
            }else if(s[i] == '{'){
                a.push('{');
            }else if(s[i] == '}'){
                if(a.top() == '{')a.pop();
                else return false;
            }
        }
        if(a.empty())return true;
        return false;
    }
};

int main(){

    return 0;
}