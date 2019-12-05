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




// class Solution {
// public:
//     string addBinary(string a, string b) {
//         if(a == "0")return b;
//         if(b == "0")return a;
//         string n1, n2;
//         for(int i = a.size() - 1;i >= 0;i--)n1.push_back(a[i]);
//         for(int i = b.size() - 1;i >= 0;i--)n2.push_back(b[i]);
//         int size1 = n1.size();
//         int size2 = n2.size();
//         if(size1 >= size2){
//             n1.push_back('0');size1++;
//             for(int i = 0;i < size1 - size2;i++)n2.push_back('0');
//             size2 = size1;
//         }else{
//             n2.push_back('0');size2++;
//             for(int i = 0;i < size2 - size1;i++)n1.push_back('0');
//             size1 = size2;
//         }
//         int iso = 0, sum = 0;
//         for(int i = 0;i < size1;i++){
//             sum = iso + n1[i] + n2[i] - '0' - '0';
//             n1[i] = sum % 2 + '0';
//             iso = sum / 2;
//         }
//         if(n1[size1-1] == '0')n1.pop_back();
//         n2.clear();
//         for(int i = n1.size() - 1;i >= 0;i--)n2.push_back(n1[i]);
//         return n2;
//     }
// };


int main(){
    
    return 0;
}