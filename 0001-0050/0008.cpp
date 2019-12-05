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
    int myAtoi(string str) {
        string::iterator in = str.begin();
        while(in[0] == ' ')str.erase(in);
        if(!((str[0] >= '0' && str[0] <= '9') || str[0] == '-' || str[0] == '+'))return 0;

        bool minus = 0;
        if(str[0] == '-'){
            minus = 1;
            str.erase(in);
        }
        else if(str[0] == '+'){
            str.erase(in);
        }
        if(!(str[0] >= '0' && str[0] <= '9'))return 0;
        
        while(in[0] == '0')str.erase(in);
        string::iterator end = in;
        while(end[0] >= '0' && end[0] <= '9')end++;
        if(int(end - in) > 10){
            if(minus)return -2147483648;
            else return 2147483647;
        }else if((int)(end - in) == 10){
            string temp(str,0,10);
            if(temp > "2147483647" && !minus)
                return 2147483647;
            if(temp > "2147483648" && minus)
                return -2147483648;
        }
        // cout<<"win!"<<endl;
        int res = 0;
        if(!minus){
            for(;in[0] >= '0' && in[0] <= '9';in++){
                res = 10 * res + (in[0] - '0');// parenthesis is missing
            }
        }
        else{
            for(;in[0] >= '0' && in[0] <= '9';in++){
                res = 10 * res - (in[0] - '0');// parenthesis is missing
            }
        }
        return res;
    }
};

int main(){

    Solution a;
    string b("2147483647");
    cout<<(b < "2147483648")<<endl;
    cout<<a.myAtoi("2147483646")<<endl;
    cout<<(char)54<<endl;
    return 0;
}