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
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* newhead = new TreeNode(0);
        TreeNode* p = newhead;
        while (root || !s.empty()) {
            if (root) {
                s.push(root);
                root = root->left;
            }
            else {
                root = s.top()->right;
                TreeNode* q = new TreeNode(s.top()->val);
                p->right = q;
                p = q;
                s.pop();
            }
        }
        return newhead->right;
    }
};
