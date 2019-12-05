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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.size() <= 1)return intervals;
        sort(intervals.begin(), intervals.end(), cmp);
        int size = intervals.size();
        int ind = 0;
        for(int i = 1;i < size;i++){
            int r = intervals[ind][1];
            if(r >= intervals[i][0]){
                intervals[ind][1] = r > intervals[i][1] ? r : intervals[i][1];
            }else{
                res.push_back(intervals[ind]);
                ind = i;
            }
        }
        res.push_back(intervals[ind]);
        return res;
    }
    static bool cmp(vector<int> a, vector<int> b){
        return a[0] < b[0];
    }
};


int main(){
    
    return 0;
}