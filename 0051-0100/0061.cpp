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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)return NULL;
        if(head->next == NULL)return head;
        int size = 0;
        ListNode* temp = head, *last = head;
        for(;temp != NULL;size++, temp = temp->next)last = temp;
        last->next = head;
        k = k % size;
        if(k == 0)return head;
        temp = head;
        for(int i = 0;i < size - k - 1;i++)temp = temp->next;
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};


int main(){
    
    return 0;
}