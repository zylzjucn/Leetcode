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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        if (root)
            findPath(root, sum, res, path);
        return res;
    }
    void findPath(TreeNode* root, int sum, vector<vector<int>> &res, vector<int> &path) {
        path.push_back(root->val);  // down
        if (!root->left && !root->right && root->val == sum)
            res.push_back(path);
        if (root->left)
            findPath(root->left, sum - root->val, res, path);
        if (root->right)
            findPath(root->right, sum - root->val, res, path);
        path.pop_back();  // up
    }
};
