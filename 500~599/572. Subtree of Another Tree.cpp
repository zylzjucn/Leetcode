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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s)
            return false;
        if (is(s, t))
            return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    bool is(TreeNode* s, TreeNode* t) {
        if (!s && !t)
            return true;
        if (!s || !t)
            return false;
        if (t->val!=s->val)
            return false;
        return is(s->left, t->left) && is(s->right, t->right);
    }
};
