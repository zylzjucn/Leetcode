/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next || !head->next->next)
            return NULL;
        ListNode *p = head->next->next, *q = head->next;
        while (p != q && p->next && p->next->next) {
            p = p->next->next;
            q = q->next;
        }
        if (p != q)
            return NULL;
        q = head;
        while (p != q) {
            p = p->next;
            q = q->next;
        }
        return p;
    }
};
