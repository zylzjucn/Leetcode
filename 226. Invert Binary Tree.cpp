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
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> s;
        s.push(root);
        TreeNode *p;
        while(!s.empty()) {
            p = s.top();
            s.pop();
            if(p) {
                s.push(p->left);
                s.push(p->right);
                swap(p->left, p->right);
            }
        }
        return root;
    }
};
