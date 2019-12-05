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
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;res.clear();
        if(nums.size() < 3)return res;
        if(nums.size() == 3){
            if(nums[0] + nums[1] + nums[2] == 0){
                res.push_back(nums);
                return res;
            }
            else{
                return res;
            }
        }

        sort(nums.begin(), nums.end());
        for(int i = 0;i < nums.size() - 2;i++){
            if(i != 0){
                if(i < nums.size() && nums[i] == nums[i - 1])continue;
            }
            int a1 = nums[i];
            int left = i + 1, right = nums.size() - 1;
            
            while(right > left){
                if(a1 + nums[right] + nums[left] == 0){
                    vector <int> temp;
                    temp.push_back(a1);
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);
                    res.push_back(temp);
                    right--;
                    left++;
                    while(right < nums.size() && nums[right] == nums[right + 1])right--;
                    while(left < nums.size() && nums[left] == nums[left - 1])left++;
                }else if(a1 + nums[right] + nums[left] < 0){
                    left++;
                    while(left < nums.size() && nums[left] == nums[left - 1])left++;
                }else if(a1 + nums[right] + nums[left] > 0){
                    right--;
                    while(right < nums.size() && nums[right] == nums[right + 1])right--;
                }
            }
        }
        return res;
    }
};
int main(){
    Solution a;
    vector <int> ques;
    ques.push_back(0);
    ques.push_back(0);
    ques.push_back(0);
    ques.push_back(0);
    vector<vector<int>> res = a.threeSum(ques);
    for(int i = 0;i < res.size();i++){
        cout << res[i][0] << " " <<res[i][1] << " " << res[i][2] << endl;
    }
    return 0;
}