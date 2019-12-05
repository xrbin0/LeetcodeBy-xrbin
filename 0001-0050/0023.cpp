#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <algorithm>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)return NULL;
        vector<ListNode*>::iterator in = lists.begin();
        for(;in < lists.end();){
            if((*in) == NULL){
                lists.erase(in);
            }
            else{
                in++;
            }
        }
        if(lists.size() == 0)return NULL;
        ListNode* res, *end;
        
        sort(lists.begin(), lists.end(),cmp);
        res = lists[lists.size() - 1];
        end = res;
        if(lists[lists.size() - 1]->next == NULL){
            lists.pop_back();
        }
        else
            lists[lists.size() - 1] = lists[lists.size() - 1]->next;

        while(lists.size() != 0){
            // sort(lists.begin(), lists.end(),cmp);

            end->next = lists[lists.size() - 1];
            end = end->next;
            lists[lists.size() - 1] = lists[lists.size() - 1]->next;
            if(lists[lists.size() - 1] == NULL){
                lists.pop_back();
            }else{
                for(int i = lists.size() - 1;i > 0;i--){
                    if(lists[i]->val > lists[i - 1]->val){
                        ListNode* temp = lists[i];
                        lists[i] = lists[i + 1];
                        lists[i + 1] = temp;
                    }else break;
                }
            }
        }
        return res;
    }

    static bool cmp(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};



int main(){

    Solution a;
    vector<ListNode*> b;
    ListNode* c = new ListNode(1);
    ListNode* d = NULL;
    b.push_back(d);
    b.push_back(c);
    cout << a.mergeKLists(b)->val<<endl;
    return 0;
}