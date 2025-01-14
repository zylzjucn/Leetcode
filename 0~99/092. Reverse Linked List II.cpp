/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* newhead = new ListNode();
        newhead->next = head;
        ListNode* pre = newhead;
        int pos = 1;
        for (; pos < left; pos++, pre = pre->next);
        ListNode* cur = pre->next;
        ListNode* tail = cur;
        while (pos++ < right) {
            pre->next = tail->next;
            tail->next = tail->next->next;
            pre->next->next = cur;
            cur = pre->next;
        }
        return newhead->next;
    }
};
