#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>
#include<list>
#include <stdio.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int counts = 0;
    int m = 0,c = 0;
    int ar[12];
    string res;
    bool flag;
    string getPermutation(int n, int k) {
        flag = 0;
        m = n; c = k;ar[0] = 0;ar[1] = 1;
        for(int i = 2;i < 12;i++)ar[i] = ar[i - 1] * i;
        vector <int> nums;
        for(int i = 1;i <= n;i++)nums.push_back(i);
        permute(nums);
    }
    void permute(vector <int> nums) {
        if(flag)return;
        for(int i = 0;i < nums.size();i++){
            if(c > ar[nums.size() - 1]){
                c -= ar[nums.size() - 1];
            }
            else{
                res.push_back(nums[i] + '0');
                nums.erase(nums.begin() + i);
                permute(nums);
                break;
            }
        }
        if(flag != 0 && c == 0){
            res.push_back(nums[0] + '0');
            flag = 1;
        }
    }
};


int main(){
    
    return 0;
}