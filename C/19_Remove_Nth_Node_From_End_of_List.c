/**
    * File Name: 19_Remove_Nth_Node_From_End_of_List.c
    * Author: Louis Xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: 03/21/16
*/

/**
 * Given a linked list, remove the nth node from the end of list and return its head.
 * 
 * For example,
 * Given linked list: 1->2->3->4->5, and n = 2.
 *
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
*/

/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     struct ListNode *next;
 *      * };
 *       */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *p, *r;
    int cnt = 0;

    if (!head) 
        return NULL;

    p = head;
    while (p != NULL) {
        p = p->next;
        cnt++;
    }

    p = r = head;
    for (int i = 0; i < cnt - n; i++) {
        r = p;
        p = p->next;
    }
    if (cnt == n) {
        head = head->next;
    } else {
        r->next = p->next;
    }

    return head;
}
