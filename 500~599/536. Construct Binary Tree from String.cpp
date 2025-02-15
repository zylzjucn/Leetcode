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
        return str2tree(s, 0, s.length() - 1);
    }

    TreeNode* str2tree(const string& s, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int i = start;
        for (; i <= end && (s[i] == '-' || isdigit(s[i])); i++);
        int val = stoi(s.substr(start, i - start));
        TreeNode* node = new TreeNode(val);
        if (i > end) {
            return node;
        }
        int count = 0;
        int j = i;
        for (; j <= end; j++) {
            if (s[j] == '(') {
                count++;
            } else if (s[j] == ')') {
                count--;
            }
            if (count == 0) {
                break;
            }
        }
        node->left = str2tree(s, i + 1, j - 1);
        node->right = j > end ? nullptr : str2tree(s, j + 2, end - 1);
        return node;
    }
};
