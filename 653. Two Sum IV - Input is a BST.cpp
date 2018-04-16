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
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> s;
        set<int> past;
        while (root || !s.empty()) {
            if (root) {
                if (past.find(k - root->val) != past.end())
                    return true;
                past.insert(root->val);
                s.push(root);
                root = root->left;
            }
            else {
                root = s.top()->right;
                
                s.pop();
            }
        }
        return false;
    }
};
