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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        stack<int> s1;
        stack<int> s2;
        inorderleft(root, target, s1);
        inorderright(root, target, s2);
        while (res.size() < k) {
            if (s1.empty()) {
                res.push_back(s2.top());
                s2.pop();
            }
            else if (s2.empty()) {
                res.push_back(s1.top());
                s1.pop();
            }
            else if (abs(s1.top() - target) < abs(s2.top() - target)) {
                res.push_back(s1.top());
                s1.pop();
            }
            else {
                res.push_back(s2.top());
                s2.pop();
            }
        }
        return res;
    }
    
    void inorderleft(TreeNode* root, double& target, stack<int>& s) {
        if (!root)
            return;
        inorderleft(root->left, target, s);
        if (root->val <= target)
            s.push(root->val);
        else
            return;
        inorderleft(root->right, target, s);
    }
    void inorderright(TreeNode* root, double& target, stack<int>& s) {
        if (!root)
            return;
        inorderright(root->right, target, s);
        if (root->val > target)
            s.push(root->val);
        else
            return;
        inorderright(root->left, target, s);
    }
};
