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
    bool isBalanced(TreeNode* root) {
        return depth(root) != -1;
    }
    int depth(TreeNode* root) {
        if(!root)
            return 0;
        int l = depth(root->left), r = depth(root->right);
        if (l == -1 || r == -1 || abs(r - l) > 1)
            return -1;
        else
            return max(l, r) + 1;
    }
};
