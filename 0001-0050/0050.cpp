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
    double myPow(double x, int n) {
        if(n == 0)return 1;
        if(n == 1)return x;
        if(n == -1)return 1/x;

        int temp = abs(n);
        int ind1 = 0;
        for(;temp != 0;ind1++)temp >> 1;
        double *rem = new double[ind1 + 3];
        rem[0] = 1; rem[1] = x;
        for(int i = 2;i < ind1 + 2;i++){
            rem[i] = rem[i] * rem[i];
        }
        double res = 1;
        temp = abs(n);
        for(int i = 1;temp != 0 && i < ind1 + 2;i++){
            if((temp & 1) == 1){
                res *= rem[i];
            }
            temp = temp >> 1;
        }
        if(n < 0)return 1/res;
        return res;
    }
};


int main(){
    
    return 0;
}