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
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int l1 = 0, r1 = 0;
        TreeNode* l = root, * r = root;
        while(l) {
            l = l->left;
            l1++;
        }
        while(r) {
            r = r->right;
            r1++;
        }
        if (l1 == r1)
            return pow(2, l1) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
