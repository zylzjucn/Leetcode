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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* head2 = even;
        while (true) {
            odd->next = even->next;
            if (!odd->next)
                break;
            odd = odd->next;
            even->next = odd->next;
            if (!even->next)
                break;
            even = even->next;
        }
        odd->next = head2;
        return head;
    }
};
