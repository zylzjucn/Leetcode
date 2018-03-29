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
    int countUnivalSubtrees(TreeNode* root) {
        int sum = 0;
        is(root, sum);
        return sum;
    }
    
    bool is(TreeNode* root, int &sum) {
        if (!root)
            return true;
        bool a = is(root->left, sum);  // should be do like this cos if in one sentence, the later ones might not be called
        bool b = is(root->right, sum);  // if the first one is false in &&
        if (a && b && (!root->left || root->left->val == root->val) && (!root->right || root->right->val == root->val)) {
            sum++;
            return true;
        }
        return false;
    }
};
