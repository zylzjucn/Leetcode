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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        f(root, v);
        return v;
    }
    void f(TreeNode* root, vector<int> &v) {
        if(!root)
            return;
        f(root->left, v);
        f(root->right, v);
        v.push_back(root->val);
    }
};
