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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        map<int, vector<int>> m;
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 0);
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int pos = q.front().second;
            q.pop();
            m[pos].push_back(node->val);
            if (node->left) {
                q.emplace(node->left, pos - 1);
            }
            if (node->right) {
                q.emplace(node->right, pos + 1);
            }
        }
        for (const auto& p : m) {
            res.push_back(p.second);
        }
        return res;
    }
};
