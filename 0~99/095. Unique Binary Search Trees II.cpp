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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> v;
        if (n == 0)
            return v;
        return build(1, n);
    }
    vector<TreeNode*> build(int start, int end) {
        vector<TreeNode*> res;
        if (start > end) {
            res.push_back(NULL);
            return res;
        }
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> l = build(start, i - 1);
            vector<TreeNode*> r = build(i + 1, end);
            for (int j = 0; j < l.size(); j++) {
                for (int k = 0; k < r.size(); k++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l[j];
                    root->right = r[k];
                    res.push_back(root);
                }
            }
            
        }
        return res;
    }
};
