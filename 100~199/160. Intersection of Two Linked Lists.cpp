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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if (!headA || !headB)
            return NULL;
        ListNode *p = headA;
        ListNode *q = headB;
        while(1) {
            if (p == q)
                return p;
            p = p->next;
            q = q->next;
            if (!p && !q)
                break;
            if (!p)
                p = headB;
            if (!q)
                q = headA;
            
        }
        return NULL;
    }
};
