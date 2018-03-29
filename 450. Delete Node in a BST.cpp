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
    TreeNode* deleteNode(TreeNode* root, int k) {
        if (!root)
            return root;
        if (root->val > k)
            root->left = deleteNode(root->left, k);
        else if (root->val < k)
            root->right = deleteNode(root->right, k);
        else {
            if (!root->left)
                return root->right;
            else if (!root->right)
                return root->left;
            TreeNode *p = find(root->right);
            root->val = p->val;
            root->right = deleteNode(root->right, root->val);
        }
        return root;
    }
    TreeNode* find(TreeNode* root) {
        while(root->left)
            root = root->left;
        return root;
    }
};
