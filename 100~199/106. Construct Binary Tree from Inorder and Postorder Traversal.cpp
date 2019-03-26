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
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        if (in.size() == 0)
            return NULL;
        TreeNode* root = new TreeNode(post.back());
        int i = 0;
        for (; in[i] != root->val; ++i);
        vector<int> inl(in.begin(), in.begin() + i);
        vector<int> inr(in.begin() + i + 1, in.end());
        vector<int> postl(post.begin(), post.begin() + i);
        vector<int> postr(post.begin() + i, post.end() - 1);
        root->left = buildTree(inl, postl);
        root->right = buildTree(inr, postr);
        return root;
    }
};
