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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *p = head, *q = head;
        while (p->next && p->next->next) {
            p = p->next->next;
            q = q->next;
        }
        p = q->next;
        q->next = NULL;
        return merge(sortList(head), sortList(p));
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *head, *p1, *p2, *cur;
        if (l1->val < l2->val) {
            head = l1;
            p1 = l1->next;
            p2 = l2;
        }
        else {
            head = l2;
            p2 = l2->next;
            p1 = l1;
        }
        cur = head;
        while (p1 && p2) {
            if (p1->val < p2->val) {
                cur->next = p1;
                p1 = p1->next;
            }
            else {
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
        }
        if (!p1)
            cur->next = p2;
        else
            cur->next = p1;
        return head;
    }
};
