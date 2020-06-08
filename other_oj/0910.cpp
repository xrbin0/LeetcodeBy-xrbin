#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        for(int i = 0;i < A.size();i++){
            A[i] += K;
        }
        sort(A.begin(), A.end());
        int min = A[0], max = A[A.size() - 1], res = max - min;
        int secondMax = max - 2*K;
        for(int i = A.size() - 1;i > 0;i--){
            A[i] -= 2 * K;
            max = mymax(A[i-1], secondMax);
            min = mymin(min,A[i]);
            res = mymin(res, max-min);
        }
        return res;
    }
    int mymax(int a, int b){ return a > b ? a : b;}
    int mymin(int a, int b){ return a < b ? a : b;}
};

