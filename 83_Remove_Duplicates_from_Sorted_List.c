/**
    * File Name: 83_Remove_Duplicates_from_Sorted_List.c
    * Author: louis xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: Apr 3, 2016
*/

/**
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 *
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
	struct ListNode *p, *q;
	int flag = 0;

	if (!head || !(head->next)) {
		return head;
	}
	p = head;
	q = p->next;

	while (q) {
		if (q->val == p->val) {
			if (!flag) {
				flag = 1;
			}
			q = q->next;
			continue;
		}
		if (flag) {
			p->next = q;
			flag = 0;
		}
		p = q;
		q = q->next;
	}
	if (flag) {
	    p->next = q;
	}

	return head;
}
