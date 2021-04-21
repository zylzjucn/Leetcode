/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if (!root)
            return 0;
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        while (q.size() > 1) {
            TreeNode* p = q.front();
            q.pop();
            if (!p) {
                sum = 0;
                q.push(nullptr);
            }
            else {
                sum += p->val;
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
            }
        }
        return sum;
    }
};
