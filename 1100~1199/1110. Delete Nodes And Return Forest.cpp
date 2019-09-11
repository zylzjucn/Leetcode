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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> s(to_delete.begin(), to_delete.end());
        find(root, res, s, true);
        return res;
    }
    
    TreeNode* find(TreeNode* root, vector<TreeNode*>& res, unordered_set<int>& s, bool isroot) {
        if (!root)
            return NULL;
        bool deleted = s.count(root->val);
        if (isroot && !deleted)
            res.push_back(root);
        root->left = find(root->left, res, s, deleted);
        root->right = find(root->right, res, s, deleted);
        return deleted ? NULL : root;
    }
};

