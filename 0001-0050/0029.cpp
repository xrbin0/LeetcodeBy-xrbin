#include "0000.h"

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0x80000000 && divisor == -1)return 0x7fffffff;
        if(dividend == 0x80000000 && divisor == 2)return -1073741824;
        if(dividend == divisor)return 1;
        if(divisor == 1)return dividend;
        long long int dend = dividend;
        long long int sor = divisor;
        if(dend + sor == 0)return -1;
        // vector <int> res;
        int res[36];
        int resind = 0;
        sor = abs(sor);
        dend = abs(dend);
        // cout<<sor<<" "<<dend<<endl;
        
        long long int mul[36];
        mul[0] = sor;
        for(int i = 1;mul[i-1] < 0x3fffffffffffffff && i < 36;i++){
            mul[i] = (mul[i-1] << 1);
        }
        
        int ind = -1;
        for(;dend > mul[ind+1];ind++);
        if(ind == -1)return 0;
        dend -= mul[ind];
        res[resind++] = ind;
        for(ind--;dend > 0 && ind >= 0;ind--){
            if(dend > mul[ind]){
                dend -= mul[ind];
                res[resind++] = ind;
            }
        }
        int lres = 0;
        for(int i = 0;i < resind;i++){
            lres += (1 << res[i]);
        }
        // cout<<lres<<" ";
        if(dividend < 0 && divisor > 0)lres = -lres;
        if(dividend > 0 && divisor < 0)lres = -lres;
        // cout<<lres<<endl;
        return lres;
    }
};