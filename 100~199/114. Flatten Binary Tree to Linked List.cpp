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
    void flatten(TreeNode* root) {
        TreeNode* p;
        while (root) {
            if (root->left && root->right) {
                p = root->left;
                while (p->right)
                    p = p->right;
                p->right = root->right;
            }
            if (root->left) {
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
    }
};
