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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        in1(root, v);
        return v;
    }
    void in1(TreeNode* root, vector<int> &v) {
        in(root, v);
    }
    void in(TreeNode* root, vector<int> &v) {
        if(root) {
            in1(root->left, v);
            v.push_back(root->val);
            in1(root->right, v);
        }
    }
};
