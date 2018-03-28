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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *first = new ListNode(0), *p = first, *q = first;
        first->next = head;
        stack<int> s;
        for (int i = 0; i < m; i++, p = p->next, q = q->next);
        while (i <= n) {
            s.push(p->val);
            p = p->next;
            i++;
        }
        while (!s.empty()) {
            q->val = s.top();
            s.pop();
            q = q->next;
        }
        return first->next;
    }
};
