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
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL || head->next == NULL || m == n)return head;
        ListNode* mhead = new ListNode(0);
        mhead->next = head;
        ListNode* temp = head;
        ListNode* ce = head;
        ListNode* rem = head;
        for(int j = 1;temp != NULL && j < n;j++){
            temp = temp->next;
            if(temp == NULL)return head;
        }
        for(int j = 1;ce != NULL && j < m;j++)ce = ce->next;
        for(;m < n;m++){
            rem = ce->next->next;
            ce->next->next = temp->next;
            temp->next = ce->next;
            ce->next = rem;
        }
        return mhead->next;
    }
};

int main(){
    
    return 0;
}