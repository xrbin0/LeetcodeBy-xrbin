#include "0000.h"

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *tail = NULL;
	struct ListNode* add = l1;
	int O = 0;
	while (add != NULL && l2 != NULL){
		//cout << "add->val = " << add->val << endl;
		//cout << "l2->val = " << l2->val << endl;
		int add1 = add->val + l2->val + O;
		add->val = add1 % 10;
		//cout << "add->val = " << add->val << endl << endl;
		O = add1 / 10;

		if (add->next == NULL && l2->next == NULL) {
			if (O == 1){
				struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
				p->next = NULL;
				p->val = 1;
				add->next = p;
			}
			break;
		}
		else if (add->next == NULL){
			l2 = l2->next;
			while (l2 != NULL){
				int add2 = l2->val + O;
				struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
				p->next = NULL;
				p->val = add2 % 10;
				O = add2 / 10;       //666
				add->next = p;
				add = p;
				l2 = l2->next;
				if (l2 == NULL && O == 1){
					struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
					p->next = NULL;
					p->val = 1;
					add->next = p;
				}
			}
			break;
		}
		else if (l2->next == NULL){
            add = add->next;
			while (add != NULL){
				int add3 = add->val + O;
				add->val = add3 % 10;
				O = add3 / 10;
				if (add->next == NULL && O == 1){
					struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
					p->next = NULL;
					p->val = 1;
					add->next = p;
                    break;
				}
				add = add->next;
			}
			break;
		}
		add = add->next;
		l2 = l2->next;
	}
	return l1;
}
