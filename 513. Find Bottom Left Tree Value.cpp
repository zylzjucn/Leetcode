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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        TreeNode* res;
        TreeNode* p = NULL;
        while (q.size() > 1) {
            if (!p)
                res = q.front();
            p = q.front();
            q.pop();
            if (!p)
                q.push(NULL);
            else {
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
            }
        }
        return res->val;
    }
};
