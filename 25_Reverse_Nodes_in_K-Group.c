/**
    * File Name: 25_Reverse_Nodes_in_K-Group.c
    * Author: Louis Xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: 03/23/16
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
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        num  -= k;
    }
    return prehead->next;
}
