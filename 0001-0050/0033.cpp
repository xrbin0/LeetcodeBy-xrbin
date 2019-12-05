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
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int fir = 0;
        while(1){
            if(nums[(fir-1)%size] > nums[fir])break;
            fir = (fir + 1) % size;
        }
        int l = 0, r = size - 1;int mid = (l + r)/2;
        while(l <= r){
            if(nums[(mid+fir)%size] == target)return (mid+fir)%size;
            else if(nums[(mid+fir)%size] > target){
                r = mid-1;
                mid = (l + r)/2;
            }
            else if(nums[(mid+fir)%size] < target){
                l = mid+1;
                mid = (l + r)/2;
            }
        }
        return -1;
    }
};

int main(){
    
    return 0;
}