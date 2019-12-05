#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)return l2;
        if(!l2)return l1;
        ListNode *head = NULL, *temp = NULL;
        if(l1->val > l2->val){
            head = l2;
            temp = l2;
            l2 = l2->next;
        }else{
            head = l1;
            temp = l1;
            l1 = l1->next;
        }
        while(l1 != NULL && l2 != NULL){
            if(l1->val > l2->val){
                temp->next = l2;
                temp = temp->next;
                l2 = l2->next;
            }else{
                temp->next = l1;
                temp = temp->next;
                l1 = l1->next;
            }
        }
        if(l1){
            temp->next = l1;
        }
        if(l2){
            temp->next = l2;
        }
        return head;
    }
};

int main(){
    
    return 0;
}