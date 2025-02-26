/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "";
        }
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> v;
        int start = 0;
        while (start < data.length()) {
            int end = start + 1;
            for (; end < data.length() && data[end] != ','; end++);
            v.push_back(stoi(data.substr(start, end - start)));
            start = end + 1;
        }
        return deserialize(v, 0, v.size() - 1);
    }

    TreeNode* deserialize(const vector<int>& v, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int i = start + 1;
        for (; i < v.size() && v[i] < v[start]; i++);
        TreeNode* root = new TreeNode(v[start], deserialize(v, start + 1, i - 1), deserialize(v, i, end));
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
