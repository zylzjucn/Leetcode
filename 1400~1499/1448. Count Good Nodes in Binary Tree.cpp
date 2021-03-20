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
    int goodNodes(TreeNode* root) {
        int res = 1;
        find(root->left, root->val, res);
        find(root->right, root->val, res);
        return res;
    }
    
    void find(TreeNode* root, int max_met, int& res) {
        if (!root)
            return;
        if (max_met <= root->val)
            res++;
        find(root->left, max(root->val, max_met), res);
        find(root->right, max(root->val, max_met), res);
    }
};
