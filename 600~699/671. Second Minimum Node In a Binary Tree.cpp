/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (!root->left) {
            return -1;
        }
        if (root->left->val != root->right->val) {
            if (root->left->val == root->val) {
                int left = findSecondMinimumValue(root->left);
                return left == -1 ? root->right->val : min(left, root->right->val);
            }
            else {
                int right = findSecondMinimumValue(root->right);
                return right == -1 ? root->left->val : min(right, root->left->val);
            }
        }
        int left = findSecondMinimumValue(root->left);
        int right = findSecondMinimumValue(root->right);
        return left == -1 ? right : right == -1 ? left : min(left, right);
    }
};
