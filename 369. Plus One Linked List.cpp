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
    ListNode* plusOne(ListNode* head) {
        ListNode* newhead = new ListNode(0);
        newhead->next = head;
        ListNode* pre = newhead;
        ListNode* cur = head;
        while (cur) {
            if (cur->val != 9)
                pre = cur;
            cur = cur->next;
        }
        while (pre) {
            pre->val = (pre->val + 1) % 10;
            pre = pre->next;
        }
        return newhead->val == 0 ? head : newhead;
    }
};
