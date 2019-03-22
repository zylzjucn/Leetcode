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
    TreeNode* sortedArrayToBST(vector<int>& n) {
        if (n.size() == 0)
            return NULL; 
        if (n.size() == 1)
            return new TreeNode(n[0]);
        int m = n.size() / 2;
        TreeNode* root = new TreeNode(n[m]);
        vector<int> l(n.begin(), n.begin()+m);
        vector<int> r(n.begin() + m + 1, n.end());
        root->left = sortedArrayToBST(l);
        root->right = sortedArrayToBST(r);
        return root;
    }
};
