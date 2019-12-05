
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include<list>
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)return NULL;
        if(head->next == NULL)return head;
        ListNode *morehead = new ListNode(0);
        morehead->next = head;
        head = morehead;
        ListNode* temp = morehead, *rem;
        bool flag = 0;
        while(head->next->next != NULL){
            if(head->next->val == head->next->next->val){
                temp = head->next->next;
                head->next->next = temp->next;
                // delete temp;
                flag = 1;
                if(head->next->next == NULL){
                    rem = head->next;
                    head->next = NULL;
                    delete rem;
                    return morehead->next;
                }
            }else{
                if(flag == 1){
                    temp = head->next;
                    head->next = temp->next;
                    flag = 0;
                    // delete temp;
                }
                else head = head->next;
            }
        }
        return morehead->next;
    }
};


int main(){
    
    return 0;
}
