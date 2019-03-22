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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> v,v1;
        if (!root)
            return res;
        queue<TreeNode*> q;
        int i, h = 1;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            if (q.front()) {
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                v.push_back(q.front()->val);
                q.pop();
            }
            else {
                if(h % 2 == 0) {
                    for (i = v.size() - 1; i >= 0; i--)
                        v1.push_back(v[i]);
                    v = v1;
                    v1.clear();
                }
                res.push_back(v);
                v.clear();
                q.pop();
                if (!q.empty()) {
                    q.push(NULL);
                    h++;
                }
            }
        }
        return res;
    }
};
