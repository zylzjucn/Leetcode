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
    ListNode* mergeKLists(vector<ListNode*>& l) {
        if (l.size() == 0)
            return NULL;
        while (l.size() > 1) {
            l.push_back(merge(l[0], l[1]));
            l.erase(l.begin());
            l.erase(l.begin());
        }
        return l[0];
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        if (l1->val < l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        }
        if(l1->val >= l2->val) {
            l2->next = merge(l2->next, l1);
            return l2;
        }
    }
};
