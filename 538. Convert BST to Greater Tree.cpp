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
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        add(root, sum);
        return root;
    }
    
    void add(TreeNode* root, int &sum) {
        if (root) {
            add(root->right, sum);
            sum += root->val;
            root->val = sum;
            add(root->left, sum);
        }
    }
    
};
