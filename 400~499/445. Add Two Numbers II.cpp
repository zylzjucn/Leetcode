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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        for (auto& p =  l1; p; p = p->next)
            s1.push(p->val);
        for (auto& p =  l2; p; p = p->next)
            s2.push(p->val);
        int carry = 0;
        ListNode* head = NULL;
        while (!s1.empty() && !s2.empty()) {
            ListNode* q = new ListNode(s1.top() + s2.top() + carry);
            carry = q->val / 10;
            q->val %= 10;
            s1.pop();
            s2.pop();
            q->next = head;
            head = q;
        }
        while (!s1.empty()) {
            ListNode* q = new ListNode(s1.top() + carry);
            carry = q->val / 10;
            q->val %= 10;
            s1.pop();
            q->next = head;
            head = q;
        }
        while (!s2.empty()) {
            ListNode* q = new ListNode(s2.top() + carry);
            carry = q->val / 10;
            q->val %= 10;
            s2.pop();
            q->next = head;
            head = q;
        }
        if (carry == 1) {
            ListNode* q = new ListNode(1);
            q->next = head;
            head = q;
        }
        return head;
    }
};
