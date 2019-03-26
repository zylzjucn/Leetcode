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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        find(root, res);
        return res;
    }
    int find(TreeNode* root, int &res) {
        if (!root)
            return 0;
        int l = find(root->left, res);
        int r = find(root->right, res);
        res = max(res, l + r);
        return max(l, r) + 1;
    }
};
