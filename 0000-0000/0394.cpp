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
        int index1;
        int index2;
        int nums;
    };
    string decodeString(string s) {
        stack<node> sa;
        for(int i = 0;i < s.size();){
            if(s[i] >= 'a' && s[i] <= 'z')i++;
            else if(s[i] >= '0' && s[i] <= '9'){
                // cout<<s[i]<<endl;
                node temp;
                temp.index1 = i;
                temp.nums = s[i] - '0';i++;
                for(;s[i] >= '0' && s[i] <= '9';i++)temp.nums = temp.nums * 10 + s[i] - '0';
                i++;//Skip the bracket
                temp.index2 = i;
                sa.push(temp);
            }else if(s[i] == ']'){
                node temp = sa.top();
                sa.pop();
                string str2(s, temp.index2, i - temp.index2);
                s.erase(s.begin() + temp.index1, s.begin() + i + 1);
                int sizes = str2.size();
                i = temp.index1;
                for(int j = 0;j < temp.nums;j++){
                    s.insert(temp.index1, str2);
                    i+=sizes;
                }
            }else i++;
        }
        return s;
    }
};

int main(){
    Solution a;
    string b = "2[abc]3[cd]ef";
    cout<<a.decodeString(b);
    return 0;
}