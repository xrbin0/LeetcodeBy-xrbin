#include <bits/stdc++.h>

/* Definition for singly-linked list. */
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)return 0;
        ListNode *t1 = head, *t2 = head;
        while(1){
            t2 = t2->next;
            if(t1)t1 = t1->next;
            if(t1)t1 = t1->next;
            if(t1 == t2 && t1)return 1;
            if(t1 == t2)return 0;
        }
        return 0;
    }
};