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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        TreeNode* newroot = new TreeNode(0);
        newroot->left = root;
        vector<int> v;
        while (newroot->left) {
            res.push_back(v);
            trim(res, newroot);
        }
        return res;
    }
    
    void trim(vector<vector<int>>& res, TreeNode* root) {
        if (!root || (!root->left && !root->right))
            return;
        if (root->left) {
            if (!root->left->left && !root->left->right) {
                res.back().push_back(root->left->val);
                root->left = NULL;
            }
            else
                trim(res, root->left);
        }
        if (root->right) {
            if (!root->right->left && !root->right->right) {
                res.back().push_back(root->right->val);
                root->right = NULL;
            }
            else
                trim(res, root->right);
        }
    }
};
