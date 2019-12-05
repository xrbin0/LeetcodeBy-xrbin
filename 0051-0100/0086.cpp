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
    ListNode* partition(ListNode* head, int x) {
        if(!head)return NULL;
        if(!head->next)return head;
        ListNode* r = new ListNode(0);
        ListNode* rem = r, *ano = NULL, *temp = NULL;
        r->next = head;bool flag = 1;
        while(r->next){
            if(r->next->val < x){
                
                if(flag){
                    ano = r->next;
                    temp = ano;
                    flag = 0;
                }else{
                    ano->next = r->next;
                    ano = ano->next;
                }
                r->next = r->next->next;
            }else r = r->next;
        }
        if(temp){
            ano->next = rem->next;
            return temp; 
        }
        else return rem->next;
    }
};


int main(){
    
    return 0;
}