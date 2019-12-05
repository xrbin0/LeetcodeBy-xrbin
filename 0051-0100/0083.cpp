#include "0000.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)return NULL;
        ListNode* temp = head;
        while(head->next != NULL){
            if(head->val == head->next->val){
                head->next = head->next->next;
            }else{
                head = head->next;
            }
        }
        return temp;
    }
};