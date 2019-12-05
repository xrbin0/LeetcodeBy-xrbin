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
    int jump(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)return 0;
        int count = 1;
        int n = nums.size();
        int max = nums[0];
        for(int i = 1; i < n;i++){
            if(max >= n - 1)return count;
            for(int j = i, k = max;j < n && j <= k;j++){
                if(nums[j] + j > max)max = nums[j] + j;
            }
            count++;
        }
        return 0;
    }
};

int main(){

    

    return 0;
}