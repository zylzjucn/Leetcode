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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return head;
        ListNode* first = new ListNode(head->val - 1), *pre = first, *p = first;
        while (head) {
            if (pre->val != head->val && (!head->next || head->val != head->next->val)) {
                p->next = head;
                p = p->next;
            }
            pre = head;
            head = head->next;
        }
        p->next = NULL;
        return first->next;
    }
};
