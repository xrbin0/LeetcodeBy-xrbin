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
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> res(2,-1);
        int l = 0, r = size - 1;int mid = (l + r)/2;
        while(l <= r){
            if(nums[mid] == target){
                int fi = mid - 1,la = mid + 1;
                for(;fi >= 0 && nums[fi] == nums[fi + 1];fi--);
                for(;la < size && nums[la] == nums[la - 1];la++);
                res[0] = fi + 1;
                res[1] = la - 1;
                return res;
            }
            else if(nums[mid] > target){
                r = mid-1;
                mid = (l + r)/2;
            }
            else if(nums[mid] < target){
                l = mid+1;
                mid = (l + r)/2;
            }
        }
        return res;
    }
};

int main(){
    
    return 0;
}