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
    bool isSymmetric(TreeNode* root) {
        return mir(root, root);
    }
    bool mir(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL)
            return p == q;
        return p->val == q->val && mir(p->left, q->right) && mir(p->right, q->left);
    }
};
