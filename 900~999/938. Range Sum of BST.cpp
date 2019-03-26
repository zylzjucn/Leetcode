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
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        stack<TreeNode*> s;
        while (root || !s.empty()) {
            if (root) {
                if (root->val <= R && root->val >= L)
                    sum += root->val;
                s.push(root);
                root = root->left;
            }
            else {
                root = s.top()->right;
                s.pop();
            }
        }
        return sum;
    }
};
