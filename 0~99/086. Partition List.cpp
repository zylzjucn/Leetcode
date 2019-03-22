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
    ListNode* partition(ListNode* head, int x) {
        ListNode* cur = head;
        ListNode* h1 = new ListNode(0);
        ListNode* h2 = new ListNode(0);
        ListNode* tail1 = h1;
        ListNode* tail2 = h2;
        while (cur) {
            if (cur->val < x) {
                tail1->next = cur;
                tail1 = cur;
            }
            else {
                tail2->next = cur;
                tail2 = cur;
            }
            cur = cur->next;
        }
        tail2->next = NULL;
        tail1->next = h2->next;
        return h1->next;
    }
};
