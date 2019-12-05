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
    int uniquePaths(int m, int n) {
        int n1 = m + n - 2;
        int n2 = (m - 1) < (n - 1) ? (m - 1) : (n - 1);
        long long int mul = 1;
        for(int i = 1;i <= n2;i++){
            mul = mul * (n1 - i + 1) / i;
            cout<<mul<<endl;
        }
        return mul;
    }
};


int main(){
    Solution a;
    a.uniquePaths(59,5);
    return 0;
}