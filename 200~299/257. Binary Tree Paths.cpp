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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root)
            return res;
        string s = to_string(root->val);
        if (root->left)
            find(root->left, res, s);
        if (root->right)
            find(root->right, res, s);
        if (res.size() == 0)
            res.push_back(s);
        return res;
    }
    void find(TreeNode* root, vector<string> &res, string &s) {
        string tmp = to_string(root->val);
        s.append("->").append(tmp);
        if (!root->left && !root->right)
            res.push_back(s);
        if (root->left)
            find(root->left, res, s);
        if (root->right)
            find(root->right, res, s);
        s.erase(s.end() - 2 - tmp.length(), s.end());
    }
};
