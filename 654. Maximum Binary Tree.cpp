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
    TreeNode* constructMaximumBinaryTree(vector<int>& n) {
        int nmax = n[0], j = 0;
        for (int i = 1; i < n.size(); i++)
            if (n[i] > nmax)
                nmax = n[j = i];
        TreeNode* root = new TreeNode(nmax);
        if (j > 0) {
            vector<int> n1(n.begin(), n.begin() + j);
            root->left = constructMaximumBinaryTree(n1);
        }
        if (j < n.size() - 1) {
            vector<int> n2(n.begin() + j + 1, n.end());
            root->right = constructMaximumBinaryTree(n2);
        }
        return root;
    }
};
