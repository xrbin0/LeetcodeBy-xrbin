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
    int trap(vector<int>& height) {
        if (height.size() == 0)return 0;
        int size = height.size();
        int sum = 0;
        // for(int i = 0;i < size;i++){
        //     sum += height[i];
        // }
        int ind1 = 0;
        while(ind1 < size - 2){
            int tag = ind1 + 1;
            if(height[tag] >= height[ind1]){
                ind1++;
                continue;
            }
            // cout<<ind1<<" ";
            
            // int maxin = ind1 + 1;
            for(;tag < size &&  height[tag] < height[ind1];tag++);
            if(tag == size){
                tag = ind1 + 1;
                for(int i = ind1 + 2;i < size;i++){
                    if(height[tag] < height[i])tag = i;
                }
                for(int i = ind1 + 1;i < tag;i++){
                    sum += (height[tag] - height[i]);
                    // height[i] = height[tag];
                }
                ind1 = tag;
                continue;
            }
            for(int i = ind1 + 1;i < tag;i++){
                sum += (height[ind1] - height[i]);
                // height[i] = height[ind1];
            }
            ind1 = tag;
        }
        // for(int i = 0;i < size;i++){
        //     sum -= height[i];
        // }
        return sum;
    }
};

int main(){
    
    return 0;
}