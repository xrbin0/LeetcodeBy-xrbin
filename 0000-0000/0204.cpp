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
    int countPrimes(int n) {
        if(n <= 2)return 0;
        vector <int> a;
        a.push_back(2);
        int coun = 1;
        for(int i = 3;i < n;i++){
            for(int j = 0;;j++){
                if(a[j] * a[j] > i){
                    a.push_back(i);
                    coun++;
                    break;
                }
                if(i % a[j] == 0)break;
            }
        }
        return coun;
    }
};


int main(){
    
    return 0;
}