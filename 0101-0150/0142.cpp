#include <bits/stdc++.h>


    // Definition for singly-linked list.
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(head == NULL) return head;
        ListNode *t1 = head, *t2 = head->next;
        while(t2 != NULL){
            if (t2 <= t1) return t2;
            t1 = t1->next; t2 = t2->next;
        }
        return NULL;
    }
};