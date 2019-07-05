class Solution {
public:
    struct Trie{
        vector<Trie*> child;
        bool isword;
        Trie(): isword(false), child(vector<Trie*>(26, NULL)) {}
    };
    
    vector<string> findWords(vector<vector<char>>& m, vector<string>& words) {
        vector<string> res;
        Trie *root = new Trie();
        Trie *p;
        for (auto word : words) {
            p = root;
            for (auto& c : word) {
                if (!p->child[c - 'a']) {
                    Trie *q = new Trie();
                    p->child[c - 'a'] = q;
                    p = q;
                }
            }
            p->isword = true;
        }
        for (int i = 0; i < m.size(); i++)
            for (int j = 0; j < m[0].size(); j++)
                find(res, m, i, j, "", root->child[m[i][j] - 'a']);
        return res;
    }
    
    void find(vector<string>& res, vector<vector<char>>& m, int i, int j, string s, Trie* p) {
        char c = m[i][j];
        if (c == '#' || !p)
            return;
        s += c;
        if (p->isword) {
            res.push_back(s);
            p->isword = false;
        }
        m[i][j] = '#';
        if (i > 0)
            find(res, m, i - 1, j, s, p->child[m[i - 1][j] - 'a']);
        if (i < m.size() - 1)
            find(res, m, i + 1, j, s, p->child[m[i + 1][j] - 'a']);
        if (j > 0)
            find(res, m, i, j - 1, s, p->child[m[i][j - 1] - 'a']);
        if (j < m[0].size() - 1)
            find(res, m, i, j + 1, s, p->child[m[i][j + 1] - 'a']);
        m[i][j] = c;
    }
};
