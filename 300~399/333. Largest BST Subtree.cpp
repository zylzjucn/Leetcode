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

struct Data {
    int min_val;
    int max_val;
    bool is_bst = false;
    int count;
    Data(int min_val, int max_val, bool is_bst, int count) : min_val(min_val), max_val(max_val), is_bst(is_bst), count(count) {}
};

class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        int res = 0;
        largestBSTSubtree(root, res);
        return res;
    }

    Data* largestBSTSubtree(TreeNode* root, int& res) {
        if (!root) {
            Data* data = new Data(INT_MAX, INT_MIN, true, 0);
            return data;
        }
        Data* data_left = largestBSTSubtree(root->left, res);
        Data* data_right = largestBSTSubtree(root->right, res);
        Data* data = new Data(INT_MAX, INT_MIN, false, 0);
        if (data_left->max_val < root->val && data_right->min_val > root->val && data_left->is_bst && data_right->is_bst) {
            data->min_val = min(data_left->min_val, root->val);
            data->max_val = max(data_right->max_val, root->val);
            data->is_bst = true;
            data->count = data_left->count + data_right->count + 1;
            res = max(res, data->count);
        }
        return data;
    }
};
