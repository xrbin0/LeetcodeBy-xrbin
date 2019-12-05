#include "0000.h"
class Solution {
public:
    int numTrees(int n) {
        int *a = new int[n + 3];
        a[0] = 0;
        a[1] = 1;
        a[2] = 2;
        a[3] = 5;
        for(int i = 4;i <= n;i++){
            a[i] = 2 * a[i-1];
            for(int j = 1;j < i - 1;j++){
                a[i] += a[j] * a[i - 1 - j];
            }
        }
        return a[n];
    }
};