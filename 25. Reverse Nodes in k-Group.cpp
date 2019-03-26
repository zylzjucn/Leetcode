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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* cur = head;
        while (cur && count != k) {
            count++;
            cur = cur->next;
        }
        if (count == k) {
            cur = reverseKGroup(cur, k); // cur is always the head of the list behind
            ListNode* tmp = head;
            while (count-- > 0) {
                tmp = head->next;
                head->next = cur; // put the node in front of the list behind one by one
                cur = head; // cur is always the head of the list behind
                head = tmp;
            }
            head = cur;
        }
        return head;
    }
};
