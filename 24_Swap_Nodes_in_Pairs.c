/**
    * File Name: 24_Swap_Nodes_in_Pairs.c
    * Author: Louis Xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: 03/23/16
*/

/*
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 * Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

/**
 *  * Definition for singly-linked list.
 *   struct ListNode {
 *      int val;
 *      struct ListNode *next;
 *   };
*/

void swap(int *p, int *q) {
    int tmp;

    tmp = *p;
    *p = *q;
    *q = tmp;
}

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *p = head, *q;
    struct ListNode *newHead = NULL;

    if (!p) 
        return NULL;
    if (!(p->next))
        return p;

    q = p;
    p = p->next; 
    while (p && q) {
        if (!newHead) 
            newHead = q;
        swap(&(q->val), &(p->val));
        if (!(p->next)) {
            break;
        }
        q = p->next;
        if (!(q->next)) {
            break;
        }
        p = q->next;
    }

    return newHead;
}
