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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* end = head;
        ListNode* newhead = new ListNode(0);
        newhead->next = head;
        while (end && end->next) {
            ListNode* pre = newhead;
            ListNode* cur = pre->next;
            ListNode* p = end->next;
            while (cur->val < p->val) {
                pre = cur;
                cur = cur->next;
            }
            if (p == cur)
                end = end->next;
            else {
                end->next = p->next;
                pre->next = p;
                p->next = cur;
            }
        }
        return newhead->next;
    }
};
