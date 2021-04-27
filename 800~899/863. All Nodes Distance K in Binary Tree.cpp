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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> res;
        find(root, target, K, res);
        dfs(target, K, res);
        return res;
    }
    
    int find(TreeNode* root, TreeNode* target, int K, vector<int>& res) {
        if (!root)
            return -1;
        if (root == target)
            return 1;
        int l = find(root->left, target, K, res);
        int r = find(root->right, target, K, res);
        if (l == -1 && r == -1)
            return -1;
        if (l == -1) {
            if (K == r)
                res.push_back(root->val);
            dfs(root->left, K - r - 1, res);
            return r + 1;
        }
        else {
            if (K == l)
                res.push_back(root->val);
            dfs(root->right, K - l - 1, res);
            return l + 1;
        }
    }
    
    void dfs(TreeNode* root, int K, vector<int>& res) {
        if (!root)
            return;
        if (K == 0)
            res.push_back(root->val);
        dfs(root->left, K - 1, res);
        dfs(root->right, K - 1, res);
    }
};
