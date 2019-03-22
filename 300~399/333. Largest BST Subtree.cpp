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
    int largestBSTSubtree(TreeNode* root) {
        int res = 0;
        isBST(root, res);
        return res;
    }
private:
    int isBST(TreeNode* root, int &res) {
        if (!root)
            return 0;
        int left = isBST(root->left, res);
        int right = isBST(root->right, res);
        if (left >= 0 && right >= 0 && (!root->left || root->val > treemax(root->left)) && (!root->right || root->val < treemin(root->right))) {
            res = max(res, left + right + 1);
            return left + right + 1;
        }
        return -1;
    }
    int treemax(TreeNode* root) {
        while (root->right)
            root = root->right;
        return root->val;
    }
    int treemin(TreeNode* root) {
        while (root->left)
            root = root->left;
        return root->val;
    }
};
