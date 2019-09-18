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
        if (!root)
            return "X,";
        string res;
        res.append(to_string(root->val)).append(",");
        res.append(serialize(root->left));
        res.append(serialize(root->right));
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return helper(data, i);
    }
    
    TreeNode* helper(string s, int& i) {
        if (s == "X,")  // == ""
            return nullptr;
        int j = i;
        for (; s[j] != ','; j++);
        string tmp = s.substr(i, j - i);
        i = j + 1;
        if (tmp == "X")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(tmp));
        root->left = helper(s, i);
        root->right = helper(s, i);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
