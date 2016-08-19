/**
    * File Name: 2_add_two_numbers.c
    * Author: Louis Xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: 03/08/16
*/

/**
 * You are given two linked lists representing two non-negative numbers. 
 * The digits are stored in reverse order and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.
 */

/** 
 * Examples:
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0, tmp1 = 0, tmp2 = 0, sum = 0;
    struct ListNode *node1 = l1, *node2 = l2;
    struct ListNode *answer_head = NULL, *answer_tail = NULL;

    if (l1 == NULL) 
        return l2;
    if (l2 == NULL)
        return l1;

    while (1) {
        if (node1) {
            tmp1 = node1->val;
        } else {
            tmp1 = 0;
        }
        if (node2) {
            tmp2 = node2->val;
        } else {
            tmp2 = 0;
        }

        if (node1 || node2 || carry) {
            if (node1) {
                node1 = node1->next;
            }
            if (node2) {
                node2 = node2->next;
            }
            if (!answer_head) {
                answer_head = (struct ListNode *)malloc(sizeof(struct ListNode));
                answer_head->next = NULL;
                answer_tail = answer_head;
            } else {
                answer_tail->next = (struct ListNode *)malloc(sizeof(struct ListNode));
                answer_tail = answer_tail->next;
                answer_tail->next = NULL;
            }
            sum = tmp1 + tmp2 + carry;
            answer_tail->val = sum % 10;
            carry = sum / 10;
        } else {
            return answer_head;
        }
    }
}
