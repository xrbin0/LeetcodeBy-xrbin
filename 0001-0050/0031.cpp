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
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int i = size - 2;
        for(;i >= 0 && nums[i] > nums[i + 1];i--);
        if(i == -1){
            for(int j = 0;j < size / 2;j++){
                swap(nums[j], nums[size - 1 - j]);
            }
        }else {
            int j = i;
            for(;j < size && nums[j] > nums[i];j++);
            // if(j == size){
            swap(nums[i], nums[j - 1]);
            // }else{
            //     swap(nums[i], nums[j]);
            // }
        }
    }
};
int main(){
    vector<int> a = {6,5,4,3,2,1};
    sort(a.begin() + 1, a.begin() + 3);
    for(int i = 0;i < a.size();i++)cout<<a[i]<<endl;
    return 0;
}