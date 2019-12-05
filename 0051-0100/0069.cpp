#include "0000.h"


class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)return 0;
        if(x < 4)return 1;
        if(x < 9)return 2;
        if(x < 16)return 3;
        if(x < 25)return 4;
        if(x < 36)return 5;
        if(x < 49)return 6;
        if(x < 64)return 7;
        long int l = 3, r= x / 7, mid = (l + r) / 2;
        while(l <= r){
            if(mid * mid == x){
                return mid;
            }else if(mid * mid > x){
                r = mid - 1;
                mid = (l + r) / 2;
            }else if(mid * mid < x){
                l = mid + 1;
                mid = (l + r) / 2;
            }
        }
        return r;
    }
};