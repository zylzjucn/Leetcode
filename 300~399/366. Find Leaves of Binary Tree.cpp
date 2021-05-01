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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        find(root, res);
        return res;
    }
    
    int find(TreeNode* root, vector<vector<int>>& res) {
        if (!root)
            return -1;
        int l = find(root->left, res);
        int r = find(root->right, res);
        int h = max(l, r) + 1;
        if (res.size() <= h)
            res.push_back({});
        res[h].push_back(root->val);
        return h;
    }
};
