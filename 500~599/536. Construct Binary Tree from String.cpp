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
    TreeNode* str2tree(string s) {
        if (s.length() == 0)
            return nullptr;
        if (to_string(stoi(s)) == s) {
            TreeNode* root = new TreeNode(stoi(s));
            return root;
        }
        int start = 0;
        int end = 0;
        for (; s[end] != '('; end++);
        TreeNode* root = new TreeNode(stoi(s.substr(0, end)));
        start = end + 1;
        end = start;
        int level = 1;
        while (level > 0) {
            if (s[end] == '(')
                level++;
            else if (s[end] == ')')
                level--;
            end++;
        }
        root->left = str2tree(s.substr(start, end - start - 1));
        if (end < s.length())
            root->right = str2tree(s.substr(end + 1, s.length() - end - 2));
        return root;
    }
};
