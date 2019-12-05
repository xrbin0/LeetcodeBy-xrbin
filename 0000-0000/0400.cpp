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

    int a[16] = {0, 9, 189, 2889, 38889, 488889, 5888889, 68888889, 788888889, 298954297, 104641081};
    int findNthDigit(int n) {
        if(n == 0)return 0;

        int ind = 0;
        for(;ind < 12 && n > a[ind];ind++);
        n -= a[ind - 1];

        int mods = n % ind;
        int divs = (n-1) / ind + 1;
        // cout<<divs;

        if(mods == 0){
            mods = ind;
        }
        
        int res = divs + pow(10, ind - 1) - 1;
        int last = 0;
        for(int i = 0;i < ind - mods + 1;i++){
            last = res % 10;
            res /= 10;
        }
        return last;
    }
};

int main(){
    long long int a = 9, b = 0;
    for(int i = 1;i < 13;i++){
        b += a * i;
        a *= 10;
        cout<<b<<" ";
    }
    return 0;
}