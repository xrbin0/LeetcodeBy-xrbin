#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <algorithm>
using namespace std;

/**
 * Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)return head;
        if(head->next == NULL)return head;//
        ListNode* rem = head;
        ListNode* temp1 = head;
        ListNode* temp2 = temp1->next;
        ListNode* temp3;
        if(temp2 != NULL)temp3 = temp2->next;//
        temp1->next = NULL;
        int all = 1;
        while(temp2 != NULL){
            if(all % k == 0)rem = temp2;
            all++;
            temp2->next = temp1;
            temp1 = temp2;
            temp2 = temp3;
            if(temp3 != NULL)
                temp3 = temp3->next;
        }
        // temp2 = temp1;
        // for(;temp2 != NULL;temp2 = temp2->next)cout<<temp2->val<<" ";
        int yu = all % k;
        if(yu == 0)yu += k;
        else if(yu == 2){
            // cout<<rem->val<<endl;
            temp1->next = rem->next;
            rem->next = temp1;
            temp1 = rem;
            // cout<<temp1->val<<endl;
        }
        else if(yu > 2){
            temp2 = temp1->next;
            temp3 = temp2->next;
            temp1->next = rem->next;
            rem = rem->next;
            while(temp2 != rem){
                temp2->next = temp1;
                temp1 = temp2;
                temp2 = temp3;
                if(temp3 != rem)
                    temp3 = temp3->next;
            }
        }
        // cout<<all<<endl;
        // cout<<yu<<endl;
        // return NULL;
        ListNode* temp4 = temp1;
        ListNode* temp5 = NULL;
        ListNode* temp6 = NULL;
        for(int i = 0;i < yu - 1;i++)temp4 = temp4->next;
        temp2 = temp4->next;
        temp4->next = NULL;
        if(temp2 == NULL){
            // cout<<'!'<<endl;
            return temp1;
        }

        temp5 = temp2;
        for(int i = 0;i < k - 1;i++)temp5 = temp5->next;
        temp3 = temp5->next;
        if(temp3 == NULL){
            temp5->next = temp1;
            return temp2;
        }

        while(temp3 != NULL){
            temp6 = temp5;
            for(int i = 0;temp6 != NULL && i < k;i++)temp6 = temp6->next;
            temp5->next = temp1;
            temp1 = temp2;
            temp4 = temp5;
            temp2 = temp3;
            temp5 = temp6;
            temp3 = temp6->next;
        }
        temp5->next = temp1;
        return temp2;
    }
};

int main(){
    Solution a;
    vector<int>b;
    b.push_back(1);
    b.push_back(2);
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    cout<<a.reverseKGroup(head, 3)->next->val;
    return 0;
}