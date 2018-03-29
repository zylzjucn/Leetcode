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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
        int h = 0;
        dfs(root, res, h);
        return res;
    }
    
private:
    void dfs(TreeNode* root, vector<int> &res, int h) {
        if (h >= res.size())
            res.push_back(root->val);
        else
            res[h] = root->val;
        if (root->left)
            dfs(root->left, res, h+1);
        if (root->right)
            dfs(root->right, res, h+1);
        h--;  // a sign of top down
    }
};
