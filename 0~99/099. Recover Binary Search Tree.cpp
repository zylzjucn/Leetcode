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
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* pre1 = NULL;
        TreeNode* cur = NULL;
        TreeNode* p = NULL;
        TreeNode* q = NULL;
        while (root || !s.empty()) {
            if (root) {
                s.push(root);
                root = root->left;
            }
            else {
                if (cur)
                    pre1 = cur;
                cur = s.top();
                if (pre1 && pre1->val > cur->val) {
                    if (!p)
                        p = pre1;
                    q = cur;
                }
                root = s.top()->right;
                s.pop();
            }
        }
        swap(p->val, q->val);
    }
};
