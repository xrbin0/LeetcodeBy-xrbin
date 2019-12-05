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
    int threeSumClosest(vector<int>& nums, int target){
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int ind1 = 0, ind2 = 1, ind3 = size - 1;
        int res = 0;
        int minx = 0x7fffffff;
        int temp = 0;
        
        while(ind1 < size - 2){
            target -= nums[ind1];
            while(ind2 < ind3){
                temp = target - nums[ind2] - nums[ind3];
                // cout<<temp<<endl;
                if(temp == 0)return nums[ind1] + nums[ind2] + nums[ind3];
                if(abs(temp) < minx){
                    res = nums[ind1] + nums[ind2] + nums[ind3];
                    // cout<<res<<" ";
                    minx = abs(temp);
                }
                if(temp > 0)ind2++;
                else ind3--;
            }
            target += nums[ind1];
            ind1++;
            ind2 = ind1 + 1;
            ind3 = size - 1;
        }//-4 -1 1 2
        return res;
    }
};

int main(){
    string a = "123456789";
    a.erase(a.begin() + 3, a.begin() + 6);
    cout<<a<<endl;
    return 0;
}