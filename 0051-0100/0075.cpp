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
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l < r){
            for(;nums[l] == 0;l++);
            for(;nums[r] != 0;r--);
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            l++;r--;
        }
        r = nums.size() - 1;
        while(l < r){
            for(;nums[l] == 1;l++);
            for(;nums[r] != 1;r--);
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            l++;r--;
        }
    }
};

int main(){
    
    return 0;
}