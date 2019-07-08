class TrieNode {
public:
    vector<TrieNode*> child;
    bool is_Word;
    TrieNode(): child(vector<TrieNode*>(26, NULL)), is_Word(false) {}
};

class WordDictionary {
public:
    TrieNode* root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* p = root;
        for (const auto& c : word) {
            if (!p->child[c - 'a'])
                p->child[c - 'a'] = new TrieNode();
            p = p->child[c - 'a'];
        }
        p->is_Word = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string s) {
        return find(s, root);
    }
    
private:
    bool find(string s, TrieNode* root) {
        for (int i = 0; i < s.length() && root; i++) {
            if (s[i] != '.')
                root = root->child[s[i] - 'a'];
            else {
                for (TrieNode* q : root->child) {
                    root = q;
                    if (find(s.substr(i + 1), q)) {
                        return true;
                    }
                }
            }
        }
        return root && root->is_Word;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
