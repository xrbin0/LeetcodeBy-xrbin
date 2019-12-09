#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public://将链表砍成前后两段，然后将后面一段翻转，然后再逐个拼接。
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return ;
        ListNode* AdditionalHead1 = new ListNode(0);
        AdditionalHead1->next = head;

        ListNode* slow = head, *fast = head;
        ListNode* temp = NULL;
        while(true){
            fast = fast->next;
            slow = slow->next;
            if(!fast) break;
            fast = fast->next;
            if(!fast) break;
        }
        temp = head;
        while(true){
            if(temp->next == slow){
                temp->next = NULL; break;
            }
            temp = temp->next;
        }
        slow = reversal(slow);
        fast = NULL;
        while(slow != NULL){
            fast = slow->next;
            temp = head->next;
            head->next = slow;
            slow->next = temp;
            head = head->next->next;
            slow = fast;
        }
    }
    ListNode * reversal(ListNode *head){
        if(head == NULL || head->next == NULL) return head;
        ListNode *p1 = head, *p2 = head->next, *p3 = head->next->next;
        head->next = NULL;
        while(p3){
            p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            p3 = p3->next;
        }
        p2->next = p1;
        return p2;
    }
};