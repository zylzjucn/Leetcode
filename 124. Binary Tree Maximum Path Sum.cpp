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
private:
public:
    int maxPathSum(TreeNode* root) {
        int m = INT_MIN;
        branch(root, m);
        return m;
    }
    int branch(TreeNode* root, int &m) {
        if (!root)
            return 0;
        int left = branch(root->left, m);
        int right = branch(root->right, m);
        m = max(m, max(0, left) + max(0, right) + root->val);
        return root->val + max(max(left, right), 0);
    }
};
