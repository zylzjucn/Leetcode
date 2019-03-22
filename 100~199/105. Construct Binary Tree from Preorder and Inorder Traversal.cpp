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
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        if (in.size() == 0)
            return NULL;
        TreeNode* root = new TreeNode(pre[0]);
        int i = 0;
        for (; in[i] != pre[0]; i++);
        vector<int> prel(pre.begin() + 1, pre.begin() + i + 1);
        vector<int> prer(pre.begin() + i + 1, pre.end());
        vector<int> inl(in.begin(), in.begin() + i);
        vector<int> inr(in.begin() + i + 1, in.end());
        root->left = buildTree(prel, inl);
        root->right = buildTree(prer, inr);
        return root;
    }
};
