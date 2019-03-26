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
    int closestValue(TreeNode* root, double t) {
        TreeNode* p = root->val > t ? root->left : root->right;
        if (!p)
            return root->val;
        int sub = closestValue(p, t);
        return (abs(root->val - t) < abs(sub - t)) ? root->val : sub;
    }
};
