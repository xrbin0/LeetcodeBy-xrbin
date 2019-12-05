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
    int maxSubArray(vector<int>& nums) {
        int max = 0, size = nums.size();
        int sum = 0;
        for(int i = 0;i < size;i++){
            sum += nums[i];
            if(sum <= 0){
                sum = 0;
            }
            if(sum > max)max = sum;
        }
        return max;
    }
};


int main(){
    
    return 0;
}