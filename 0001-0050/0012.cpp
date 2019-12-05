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
    string intToRoman(int num) {
        string res;
        string nums(to_string(num));
        string::iterator in = nums.begin();
        if(nums.size() == 4){
            for(int i = 0;i < in[0] - '0';i++){
                res = res +"M";
            }
            nums.erase(in);
        }
        // cout<<1<<endl;
        if(nums.size() == 3){
            if(in[0] == '0');
            else if(in[0] == 4 + '0'){
                res = res +"CD";
            }
            else if(in[0] == 9 + '0'){
                res = res +"CM";
            }
            else if(in[0] < 4 + '0'){
                for(int i = 0;i < in[0] - '0';i++){
                    res = res +"C";
                }
            }
            else{
                res = res +"D";
                for(int i = 0;i < in[0] - '5';i++){
                    res = res +"C";
                }
            }
            nums.erase(in);
        }
        // cout<<2<<endl;
        if(nums.size() == 2){
            if(in[0] == '0');
            else if(in[0] == 4 + '0'){
                res = res +"XL";
            }
            else if(in[0] == 9 + '0'){
                res = res +"XC";
            }
            else if(in[0] < 4 + '0'){
                for(int i = 0;i < in[0] - '0';i++){
                    res = res +"X";
                }
            }
            else{
                res = res +"L";
                for(int i = 0;i < in[0] - '5';i++){
                    res = res +"X";
                }
            }
            nums.erase(in);
        }
        // cout<<3<<endl;
        if(nums.size() == 1){
            if(in[0] == '0');
            else if(in[0] == 4 + '0'){
                res = res +"IV";
            }
            else if(in[0] == 9 + '0'){
                res = res +"IX";
            }
            else if(in[0] < 4 + '0'){
                for(int i = 0;i < in[0] - '0';i++){
                    res = res +"I";
                }
            }
            else{
                res = res +"V";
                for(int i = 0;i < in[0] - '5';i++){
                    res = res +"I";
                }
            }
        }
        // cout<<4<<endl;
        return res;
    }
};

int main(){

    Solution a;
    cout<<a.intToRoman(2345);
    return 0;
}