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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode* cur = root;
        TreeNode* newleft = NULL;
        TreeNode* newright = NULL;
        while (cur) {
            TreeNode* oldleft = cur->left;
            TreeNode* oldright = cur->right;
            cur->left = newleft;
            cur->right = newright;
            newright = cur;
            newleft = oldright;
            cur = oldleft;
        }
        return newright;
    }
};
