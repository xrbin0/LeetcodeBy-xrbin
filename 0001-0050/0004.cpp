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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0){
            if(nums2.size() % 2 == 0){
                return (double)(nums2[nums2.size()/2] + nums2[nums2.size()/2 - 1])/2;
            }
            else{
                return nums2[nums2.size()/2];
            }
        }
        if(nums2.size() == 0){
            if(nums1.size() % 2 == 0){
                return (double)(nums1[nums1.size()/2] + nums1[nums1.size()/2 - 1])/2;
            }
            else{
                return nums1[nums1.size()/2];
            }
        }
        int mid = (nums1.size() + nums2.size());
        // cout<<mid<<endl;
        if(mid % 2 == 1){
            mid = mid / 2;
            int begin1 = 0, end1 = nums1.size() - 1, m1 = (begin1 + end1) / 2;
            int begin2 = 0, end2 = nums2.size() - 1, m2 = (begin2 + end2) / 2;
            while(end1 + end2 - begin1 - begin2 > 10 && end1 + end2 - begin1 - begin2 > 2 * mid){
                // cout<<mid<<endl;
                if(nums1[m1] > nums2[m2]){
                    mid -= m2 - begin2; 
                    end1 = m1;
                    begin2 = m2;
                    m1 = (begin1 + end1) / 2;
                    m2 = (begin2 + end2) / 2;
                }
                else{
                    mid -= m1 - begin1;
                    end2 = m2;
                    begin1 = m1;
                    m1 = (begin1 + end1) / 2;
                    m2 = (begin2 + end2) / 2;
                }
                // cout<<"re!"<<endl;
            }
            vector <int>pre;
            for(;begin1 <= end1;begin1++){
                pre.push_back(nums1[begin1]);
            }
            for(;begin2 <= end2;begin2++){
                pre.push_back(nums2[begin2]);
            }
            sort(pre.begin(), pre.end());
            return pre[mid];
        }
        else{
            mid = mid / 2 - 1;
            int begin1 = 0, end1 = nums1.size() - 1, m1 = (begin1 + end1) / 2;
            int begin2 = 0, end2 = nums2.size() - 1, m2 = (begin2 + end2) / 2;
            while(end1 + end2 - begin1 - begin2 > 6 && end1 + end2 - begin1 - begin2 > 2 * mid){
                if(nums1[m1] > nums2[m2]){
                    mid -= m2 - begin2; 
                    end1 = m1 + 1;
                    begin2 = m2;
                    m1 = (begin1 + end1) / 2;
                    m2 = (begin2 + end2) / 2;
                }
                else{
                    mid -= m1 - begin1;
                    end2 = m2 + 1;
                    begin1 = m1;
                    m1 = (begin1 + end1) / 2;
                    m2 = (begin2 + end2) / 2;
                }
                if(end1 >= nums1.size())end1--;
                if(end2 >= nums2.size())end2--;
                // cout<<m1<<" "<<m2<<endl;
            }
            vector <int>pre;
            for(;begin1 <= end1;begin1++){
                pre.push_back(nums1[begin1]);
            }
            for(;begin2 <= end2;begin2++){
                pre.push_back(nums2[begin2]);
            }
            sort(pre.begin(), pre.end());
            double res = double(double(pre[mid] + pre[mid + 1])/2);
            return double(pre[mid] + pre[mid + 1])/2;
        }
    }
};

int main(){
    Solution a;
    vector<int> a1;
    vector<int> a2;
    a1.push_back(1);
    a1.push_back(1);
    a1.push_back(1);
    a1.push_back(1);
    a1.push_back(1);
    a1.push_back(1);
    a1.push_back(1);
    a1.push_back(1);
    a1.push_back(1);
    a1.push_back(1);
    a1.push_back(4);
    a1.push_back(4);

    a2.push_back(1);
    a2.push_back(3);
    a2.push_back(4);
    a2.push_back(4);
    a2.push_back(4);
    a2.push_back(4);
    a2.push_back(4);
    a2.push_back(4);
    a2.push_back(4);
    a2.push_back(4);
    a2.push_back(4);
    cout<<a.findMedianSortedArrays(a1,a2);

    return 0;
}