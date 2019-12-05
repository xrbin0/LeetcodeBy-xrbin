#include "0000.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0)return;
        if(m == 0)nums1 = nums2;
        int ind2 = 0;
        for(int i = 0;i < nums2.size();i++)nums1.pop_back();
        for(int i = 0;ind2 < nums2.size() && i < nums1.size();i++){
            if(nums2[ind2] <= nums1[i]){
                nums1.insert(nums1.begin() + i, nums2[ind2++]);
            }
        }
        if(ind2 < nums2.size()){
            for(;ind2 < nums2.size();ind2++)nums1.push_back(nums2[ind2]);
        }
    }
};