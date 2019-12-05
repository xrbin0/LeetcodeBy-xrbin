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
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)return 1;
        
        int n = nums.size();
        int max = nums[0];
        for(int i = 1; i < n;i++){
            for(int j = i, k = max;j < n && j <= k;j++){
                if(nums[j] + j > max)max = nums[j] + j;
            }
            
            if(max >= n - 1)return 1;
        }
        return 0;
    }
};

int main(){

    

    return 0;
}