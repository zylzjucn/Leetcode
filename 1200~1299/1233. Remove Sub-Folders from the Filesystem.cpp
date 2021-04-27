struct TrieNode {
    bool finished;
    vector<TrieNode*> children;
    TrieNode(): finished(false), children(vector<TrieNode*>(27, nullptr)) {}
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        auto cmp = [](const string& a, const string& b) {
            return a.length() < b.length();
        };
        sort(folder.begin(), folder.end(), cmp);
        unordered_set<string> s;
        TrieNode* root = new TrieNode();
        for (const auto& str : folder) {
            TrieNode* node = root;
            bool met = false;
            for (int i = 0; i < str.length(); i++) {
                int index = -1;
                if (str[i] == '/')
                    index = 26;
                else
                    index = str[i] - 'a';
                if (!node->children[index]) {
                    TrieNode* p = new TrieNode();
                    node->children[index] = p;
                }
                node = node->children[index];
                if (node->finished && i < str.length() - 1 && str[i + 1] == '/') {
                    met = true;
                    break;
                }
            }
            node->finished = true;
            if (!met)
                s.insert(str);
        }
        vector<string> res;
        for (const auto& str : s)
            res.push_back(str);
        return res;
    }
};
