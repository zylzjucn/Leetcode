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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* newhead = new ListNode(0);
        newhead->next = head;
        ListNode* pre = newhead;
        ListNode* cur = head;
        while (cur) {
            if (cur->val == val) {
                pre->next = cur->next;
                cur = pre->next;
            }
            else {
                pre = cur;
                cur = cur->next;
            }
        }
        return newhead->next;
    }
};
