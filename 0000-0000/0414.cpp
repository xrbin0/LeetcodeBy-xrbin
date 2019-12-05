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
    int thirdMax(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }else if(nums.size() == 2){
            return nums[0] > nums[1] ? nums[0] : nums[1];
        }
        int maxindex = 0;
        for(int i = 1;i < nums.size();i++){
            if(nums[i] > nums[maxindex]){
                maxindex = i;
            }else if(nums[i] == nums[maxindex]){
                nums.erase(nums.begin() + i);
            }
        }nums.erase(nums.begin() + maxindex);
        maxindex = 0;for(int i = 1;i < nums.size();i++){
            if(nums[i] > nums[maxindex]){
                maxindex = i;
            }else if(nums[i] == nums[maxindex]){
                nums.erase(nums.begin() + i);
            }
        }nums.erase(nums.begin() + maxindex);
        maxindex = 0;for(int i = 1;i < nums.size();i++){
            if(nums[i] > nums[maxindex]){
                maxindex = i;
            }else if(nums[i] == nums[maxindex]){
                nums.erase(nums.begin() + i);
            }
        }nums.erase(nums.begin() + maxindex);
        return nums[maxindex];
    }
};




int main(){

    

    return 0;
}