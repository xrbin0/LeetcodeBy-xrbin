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

class Solution {
public:
    string multiply(string num1, string num2) {
        int size1=num1.size();
        int size2=num2.size();
        if(size1 == 0 || size2 == 0)return "0";
        string res;
        for(int i = 0;i < size2 + size1;i++){
            res.push_back('0');
        }
        for(int i = size2-1;i>=0;i--){
            for(int j=size1-1;j>=0;j--){
                int temp=(res[i+j+1]-'0')+(num1[j]-'0')*(num2[i]-'0');
                res[i+j+1]=temp%10+'0';//当前位
                res[i+j]+=temp/10; //前一位加上进位，res[i+j]已经初始化为'0'，加上int类型自动转化为char，所以此处不加'0'
            }
        }
        for(;res[0] == '0';)res.erase(res.begin());
        return res;
    }
};

int main(){
    Solution a;
    string b1("5310227393536445628051202171120653895544890756210");
    string b2("15657985297554855419011");
    cout<<a.multiply(b1, b2);
    return 0;
}

// class Solution {
// public:
//     string multiply(string num1, string num2) {
//         string str1, str2;
//         int size1 = num1.size(), size2 = num2.size();
//         if(size1 == 0 || size2 == 0)return "0";
//         for(int i = size1;i > 0;i--)str1.push_back(num1[i-1]);
//         for(int i = size2;i > 0;i--)str2.push_back(num2[i-1]);
//         string res = "0";
//         string temp(str2);
//         for(int i = 0;i < size1;i++){
//             temp = str2;
//             temp.insert(0, i, '0');
//             _mul(str1[i], temp);
//             _sum(res, temp);
//         }
//         string temp1 = "";
//         int size3 = res.size();
//         for(int i = size3 - 1;i >= 0;i--){
//             temp1.push_back(res[i]);
//         }
//         return temp1;
//     }
//     void _sum(string& num1,string& num2){
//         int size1 = num1.size(), size2 = num2.size();
//         if(size1 > size2){
//             num1.push_back('0');
//             size1++;
//             for(int i = 0;i < size1 - size2;i++)
//                 num2.push_back('0');
//             size2 = size1;
//         }
//         else if(size1 <= size2){
//             num2.push_back('0');
//             size2++;
//             for(int i = 0;i < size2 - size1;i++)
//                 num1.push_back('0');
//             size1 = size2;
//         }
//         int isopsephy = 0;int sum = 0;
//         for(int i = 0;i < size1;i++){
//             sum = num1[i] - '0' + num2[i] - '0' + isopsephy;
//             num1[i] = (sum%10) + '0';
//             isopsephy = sum / 10;
//         }
//         for(;num1[num1.size() - 1] == '0';)num1.erase(num1.end()-1);
//         if(isopsephy)num1.push_back(isopsephy + '0');
//         return;
//     }

//     void _mul(char c,string& num2){
//         int isopsephy = 0, size = num2.size();
//         int mul = 0;
//         for(int i = 0;i < size;i++){
//             mul = (c - '0') * (num2[i] - '0') + isopsephy;
//             num2[i] = (char(mul % 10 + '0'));
//             isopsephy = mul / 10;
//         }
//         if(isopsephy)num2.push_back(isopsephy + '0');
//         return;
//     }
// };
