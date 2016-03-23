/**
    * File Name: 25_Reverse_Nodes_in_K-Group.c
    * Author: Louis Xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: 03/23/16
*/

/**
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 *
 * If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 *
 * You may not alter the values in the nodes, only nodes itself may be changed.
 *
 * Only constant memory is allowed.
 *
 * For example,
 * Given this linked list: 1->2->3->4->5
 *
 * For k = 2, you should return: 2->1->4->3->5
 *
 * For k = 3, you should return: 3->2->1->4->5
*/

/**
 *  * Definition for singly-linked list.
 *  * struct ListNode {
 *  *     int val;
 *  *     struct ListNode *next;
 *  * };
*/

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *prehead, *pre, *cur, *nex;
    int i, num = 0;

    if (!head || k == 1) {
        return head;
    }

    prehead = (struct ListNode *) malloc(sizeof(struct ListNode));
    prehead->next = head;

    cur = prehead;
    pre = prehead;
    while (cur = cur->next) {
        num++;
    }

    while (num >= k) {
        cur = pre->next;
        nex = cur->next;
        for (i = 1; i< k; i++) {
            cur->next = nex->next;
            nex->next = pre->next; //key step
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        num  -= k;
    }
    return prehead->next;
}
