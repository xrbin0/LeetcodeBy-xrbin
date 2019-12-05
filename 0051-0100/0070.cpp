#include "0000.h"

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)return 1;
        long int a = 1, b = 2, c = 3;
        for(int i = 3; i < n + 1;i++){
            b = a + b;
            a = b - a;
        }
        return b;
    }
};