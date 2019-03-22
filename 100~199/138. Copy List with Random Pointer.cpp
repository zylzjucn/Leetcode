/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head)
            return NULL;
        RandomListNode* l1 = head, *l2, *newhead;
        for (; l1; l1 = l1->next->next) {
            l2 = new RandomListNode(l1->label);
            l2->next = l1->next;
            l1->next = l2;
        }
        newhead = head->next;
        for (l1 = head; l1; l1 = l1->next->next) {
            if (l1->random)
                l1->next->random = l1->random->next;
        }
        for (l1 = head, l2 = newhead; l1; l1 = l1->next, l2 = l2->next) {
            l1->next = l2->next;
            if (l2->next)
                l2->next = l1->next->next;
        }
        return newhead;
    }
};
