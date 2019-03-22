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
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        help(root, sum, res);
        return res;
    }
    void help(TreeNode* root, int sum, int &res) {
        if (root)
            find(root, sum, res);
        if (root && root->left)
            help(root->left, sum, res); // care about which function you should recurse
        if (root && root->right)
            help(root->right, sum, res);
    }
    void find(TreeNode* root, int sum, int &res) {
        if (sum == root->val)
            res++;
        if (root->left)
            find(root->left, sum - root->val, res);
        if (root->right)
            find(root->right, sum - root->val, res);
    }
};
