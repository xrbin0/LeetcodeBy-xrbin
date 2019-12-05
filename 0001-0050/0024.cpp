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
 * Definition for singly-linked list.
 */
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)return head;
        ListNode* temp = head->next;
        ListNode* rem = head->next;
        while(head != NULL && head->next != NULL){
            temp = head->next;
            head->next = temp->next;
            temp->next = head;
            head = head->next;
            if(temp->next->next != NULL && temp->next->next->next != NULL)
                temp->next->next = head->next;
        }
        return rem;
    }
};

int main(){
    
    return 0;
}