/**
    * File Name: 21_Merge_Two_Sorted_Lists.c
    * Author: Louis Xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: 03/21/16
*/

/**
 * Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes of the first two lists.
 */

/**
 *  Definition for singly-linked list.
 *  struct ListNode {
 *       int val;
 *       struct ListNode *next;
 *   };
 */

/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     struct ListNode *next;
 *      * };
 *       */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p = l1, *q =l2, *r = l1, *s = l2;
    struct ListNode *head = NULL;
    if (!p) 
        return q;
    if (!q)
        return p;

    while (p && q) {
        if (p->val <= q->val) {
            if (!head)
                head = p;
            r = p;
            p = p->next;
        } else {
            if (!head) { 
                head = q;
            } else {
                r ->next = q;
            }
            s = q->next;
            q->next = p;
            r = q; 
            q = s;
        }
    }
    if (!p) 
        r->next = q;

    return head;
}
