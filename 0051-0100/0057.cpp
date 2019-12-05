#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include<list>
#include <stack>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        if(intervals.size() == 0){
            intervals.push_back(newInterval);
            return intervals;
        }
        int l = 0, r = intervals.size() - 1;
        int mid = (l + r) / 2;
        while(l <= r){
            if(intervals[mid][0] == newInterval[0]){
                intervals.insert(mid + intervals.begin(), newInterval);
                break;
            }
            else if(intervals[mid][0] > newInterval[0]){
                r = mid - 1; mid = (l + r) / 2;
            }
            else if(intervals[mid][0] < newInterval[0]){
                l = mid + 1; mid = (l + r) / 2;
            }
        }
        if(r < l)
            intervals.insert(l + intervals.begin(), newInterval);
        int fl = 1;
        for(int i = 0;i < intervals.size() - 1;i++){
            int inde = i + 1;
            if(fl && intervals[i][1] >= intervals[inde][0]){
                for(;inde < intervals.size();inde++){
                    if(intervals[i][1] >= intervals[inde][0]){
                        if(intervals[i][1] < intervals[inde][1])
                            intervals[i][1] = intervals[inde][1];
                    }else break;
                }
                fl = 0;
                i = inde - 1;
            }
            res.push_back(intervals[i]);
        }
        return res;
    }
};

int main(){
    
    return 0;
}