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
    int findTilt(TreeNode* root) {
        int res = 0;
        f(root, res);
        return res;
    }
    int f(TreeNode* root, int &res) {
        if (!root)
            return 0;
        int l = f(root->left, res);
        int r = f(root->right, res);
        res += abs(l - r);
        return l + r + root->val;
    }
};
