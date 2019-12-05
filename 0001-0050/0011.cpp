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
    int maxArea(vector<int>& height) {
        vector<int>::iterator begin = height.begin();
        vector<int>::iterator end = height.end() - 1;
        int max = (int)(end - begin) * min(end[0], begin[0]);
        while(begin < end){
            if(end[0] >= begin[0]){
                int rem = begin[0];
                while (begin < end && rem >= begin[0]){
                    begin++;
                }
                if(begin == end)break;
                // cout<<begin[0]<<" "<<end[0]<<endl;
                // cout<<(int)(begin - height.begin())<<" "<<(int)(end - height.begin())<<endl;
                if((int)(end - begin) * min(end[0], begin[0]) > max){
                    max = (int)(end - begin) * min(end[0], begin[0]);
                }
            }else{
                int rem = end[0];
                while (begin < end && end[0] <= rem){
                    end--;
                }
                if(begin == end)break;
                // cout<<begin[0]<<" "<<end[0]<<endl;
                // cout<<(int)(begin - height.begin())<<" "<<(int)(end - height.begin())<<endl;
                if((int)(end - begin) * min(end[0], begin[0]) > max){
                    max = (int)(end - begin) * min(end[0], begin[0]);
                }
            }
            // cout<<max<<endl;
        }
        return max;
    }
};



int main(){

    Solution a;
    vector<int> height;
    height.push_back(1);
    height.push_back(2);
    height.push_back(4);
    height.push_back(3);
    // height.push_back(5);
    // height.push_back(4);
    // height.push_back(8);
    // height.push_back(3);
    // height.push_back(7);
    cout << a.maxArea(height) << endl;

    return 0;
}