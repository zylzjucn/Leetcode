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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        ListNode *p = head, *q = head;
        int l = 1;
        while (p->next) {
            p = p->next;
            l++;
        }
        p->next = head;
        if (k %= l)
            for (int i = 0; i < (l - k); i++)
                p = p->next;
        q = p->next;
        p->next = NULL;
        return q;
    }
};
