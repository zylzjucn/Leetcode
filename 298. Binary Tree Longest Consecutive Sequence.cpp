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
    int longestConsecutive(TreeNode* root) {
        return count(root, NULL, 0);
    }
    int count(TreeNode* root, TreeNode* parent, int l) {
        if (!root)
            return l;
        l = (parent && root->val == parent->val+1) ? l + 1 : 1;
        return max(l, max(count(root->left, root, l), count(root->right, root, l)));
    }
};
