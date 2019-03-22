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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        if (!root)
            return 0;
        f(root, sum);
        return sum;
    }
    void f(TreeNode* root, int &sum) {
        if (!root->left && !root->right)
            sum += root->val;
        if (root->left) {
            root->left->val += 10 * root->val;
            f(root->left, sum);
        }
        if (root->right) {
            root->right->val += 10 * root->val;
            f(root->right, sum);
        }
    }
};
