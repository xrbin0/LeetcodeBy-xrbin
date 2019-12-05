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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int *vine = new int[gas.size() + 3];
        for(int i = 0;i < gas.size();i++){
            vine[i] = gas[i] - cost[i];
        }
        int res = 0;
        for(int i = 0;i < gas.size();i++){
            if(vine[i] > 0){
                int sum = 0;
                sum += vine[i];
                for(int j = i + 1;j != i;j = (j + 1)%gas.size()){
                    if(sum < 0)break;
                }
                return i;
            }
            if(i == gas.size() - 1)return -1;
        }
        return 0;
    }
};

int main(){

    

    return 0;
}