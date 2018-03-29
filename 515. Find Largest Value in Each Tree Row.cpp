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
    vector<int> largestValues(TreeNode* root) {
        vector<int> v;
        if (!root)
            return v;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int m = INT_MIN;
        while(1) {
            root = q.front();
            q.pop();
            if (!root) {
                v.push_back(m);
                m = INT_MIN;
                if (q.empty())
                    break;
                q.push(NULL);
            }
            if (root) {
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
                m = max(m, root->val);
            }
        }
        return v;
    }
};
