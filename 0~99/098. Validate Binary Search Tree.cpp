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
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        return (isValidBST(root->left) && isValidBST(root->right) && (!root->left || root->val > maxtree(root->left)) && (!root->right || root->val < mintree(root->right)));
    }
    
private:
    int maxtree(TreeNode* root) {
        while (root->right)
            root = root->right;
        return root->val;
    }
    
    int mintree(TreeNode* root) {
        while (root->left)
            root = root->left;
        return root->val;
    }
};
