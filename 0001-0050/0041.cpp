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
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        for(int i = 0;i < size;){
            if(nums[i] > 0 && nums[i] <= size){
                if(i == nums[i] - 1){
                    nums[i] = 0x80000000;
                    i++;
                    continue;
                }
                int temp = nums[nums[i] - 1];
                nums[nums[i] - 1] = 0x80000000;

                if(temp >= 1 && temp <= size)
                    nums[i] = temp;
                else i++;
            }
            else{
                i++;
            }
        }
        for(int i = 0;i < size;i++){
            if(nums[i] != 0x80000000)
                return i + 1;
        }
        return size + 1;
    }
};

int main(){
    Solution a;
    vector <int> b;
    b.push_back(1);
    b.push_back(1);
    cout<<a.firstMissingPositive(b);
    return 0;
}