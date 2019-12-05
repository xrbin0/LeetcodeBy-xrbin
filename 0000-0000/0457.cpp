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
    bool circularArrayLoop(vector<int>& nums) {
        int size = nums.size();
        vector<int> nums2(size, 0);
        for(int i = 0;i < size;i++){
            if(nums[i] < 0){
                nums2[size - i - 1] = -nums[i];
                nums[i] = 0;
            }
        }
        
        int counts = 0;int index = 0;
        for(int i = 0;i < size;i++){
            if(nums[i] && nums[i] % size != 0){
                counts = 0;
                index = i;
                while(counts < size && nums[index] != 0){
                    counts += 1;
                    index = (index + nums[index]) % size;
                    if(index == i)return true;
                }
            }
        }
        for(int i = 0;i < size;i++){
            if(nums2[i] && nums2[i] % size != 0){
                counts = 0;
                index = i;
                while(counts < size && nums2[index] != 0){
                    counts += 1;
                    index = (index + nums2[index]) % size;
                    if(index == i)return true;
                }
            }
        }
        return false;
    }
};

int main(){
    Solution a;
    vector <int> b;
    b.push_back(-1);
    b.push_back(2);
    cout<<a.circularArrayLoop(b)<<endl;
    return 0;
}