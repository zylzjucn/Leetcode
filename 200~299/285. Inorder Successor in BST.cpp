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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> s;
        bool flag = false;
        while (root || !s.empty()) {
            if (root) {
                s.push(root);
                root = root->left;
            }
            else {
                if (flag == true)
                    return s.top();
                if (s.top() == p)
                    flag = true;
                root = s.top()->right;
                s.pop();
            }
        }
        return NULL;
    }
};
