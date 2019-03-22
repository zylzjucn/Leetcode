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
    void reorderList(ListNode* head) {
        if (!head)
            return;
        ListNode* p = head;
        vector<ListNode*> v;
        while(p) {
            v.push_back(p);
            p = p->next;
        }
        int i = 0, j = v.size() - 1;
        while (i < j) {
            v[i]->next = v[j];
            i++;
            if (i == j)
                break;
            v[j]->next = v[i];
            j--;
        }
        v[i]->next = NULL;
        return;
    }
};
