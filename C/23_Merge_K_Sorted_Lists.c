/**
    * File Name: 23_Merge_K_Sorted_Lists.c
    * Author: Louis Xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: 03/23/16
*/

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
*/

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    if (l1->val <= l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode *head = NULL;
    int low, high;

    if (!lists)
        return NULL;

    if (listsSize <= 1)
        return lists[0];

    while (listsSize >= 2) {
        low = 0;
        high = listsSize - 1;
        while (low < high) {
            lists[low] = mergeTwoLists(lists[low], lists[high]);
            low++;
            high--;
        }
        if (listsSize % 2) 
            lists[0] = mergeTwoLists(lists[0], lists[high]);
        listsSize /= 2;
    }

    return lists[0];
}
