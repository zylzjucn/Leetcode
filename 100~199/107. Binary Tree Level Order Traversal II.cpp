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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> v;
        while (q.size() > 1) {
            if (!q.front()) {
                q.push(NULL);
                q.pop();
                res.push_back(v);
                v.clear();
            }
            else {
                if (q.front()->left)
                    q.push(q.front()->left);
                if (q.front()->right)
                    q.push(q.front()->right);
                v.push_back(q.front()->val);
                q.pop();
            }
        }
        res.push_back(v);
        reverse(res.begin(), res.end());
        return res;
    }
};
