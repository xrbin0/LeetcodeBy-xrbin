#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        for(int i = A.size() - 2;i > 0;i--){
            for(int j = i + 1;j < A.size();j++){
                if(A[i] > A[j]){
                    int min = i + 1;
                    for(int k = i + 2;k <= j;k++){
                        if(A[i] > A[k] && A[k] > A[min])min = k;
                    }
                    int temp = A[i];
                    A[i] = A[min];
                    A[min] = temp;
                    return A;
                }
            }
        }
        return A;
    }
};
int main(){

    return 0;
}