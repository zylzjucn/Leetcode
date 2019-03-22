/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
            return NULL;
        if (!head->next) {
            TreeNode *p = new TreeNode(head->val);
            return p;
        }
        ListNode *f = head->next, *s = head;
        for(; f->next && f->next->next; s = s->next, f = f->next->next);
        TreeNode *p = new TreeNode(s->next->val);
        f = s->next->next;
        s->next = NULL;
        p->left = sortedListToBST(head);
        p->right = sortedListToBST(f);
        return p;
    }
};
