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
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        for(int i = 2;i < size;){
            if(nums[i - 2] == nums[i-1] && nums[i] == nums[i-2]){
                nums.erase(nums.begin()+i);
                size--;
            }
            else i++;
        }
        return nums.size();
    }
};

int main(){
    
    return 0;
}