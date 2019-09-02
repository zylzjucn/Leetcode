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
    int findClosestLeaf(TreeNode* root, int k) {
        if (!root)
            return 0;
        unordered_map<TreeNode*, TreeNode*> m;
        queue<TreeNode*> q;
        unordered_set<int> s;
        DFS(m, q, s, root);
        queue<TreeNode*> leaves(q);
        while (q.front()->val != k) {
            TreeNode* p = q.front();
            if (m.count(p) && s.count(m[p]->val)) {
                q.push(m[p]);
                leaves.push(leaves.front());
                s.erase(m[p]->val);
            }
            if (p->left && s.count(p->left->val)) {
                q.push(p->left);
                leaves.push(leaves.front());
                s.erase(p->left->val);
            }
            if (p->right && s.count(p->right->val)) {
                q.push(p->right);
                leaves.push(leaves.front());
                s.erase(p->right->val);
            }
            q.pop();
            leaves.pop();
        }
        return leaves.front()->val;
    }
    
    void DFS(unordered_map<TreeNode*, TreeNode*>& m, queue<TreeNode*>& q, unordered_set<int>& s, TreeNode* root) {
        if (!root->left && !root->right)
            q.push(root);
        s.insert(root->val);
        if (root->left) {
            m[root->left] = root;
            DFS(m, q, s, root->left);
        }
        if (root->right) {
            m[root->right] = root;
            DFS(m, q, s, root->right);
        }
    }
};
