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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* temp2 = head;
        for(int i = 0;i < n;i++){
            temp = temp->next;
        }
        if(temp == NULL){
            head = head->next;
            return head;
        }
        while(temp->next != NULL){
            temp = temp->next;
            temp2 = temp2->next;
        }
        temp2->next = temp2->next->next;
        return head;
    }
};

int main(){
    
    return 0;
}