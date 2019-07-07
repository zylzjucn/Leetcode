class TrieNode {
public:
    vector<TrieNode*> child;
    bool isWord;
    TrieNode(): child(vector<TrieNode*>(26, NULL)), isWord(false) {}
};

class Trie {
private:
    TrieNode* root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = root;
        for (const auto& c : word) {
            if (p->child[c - 'a']) {
                p = p->child[c - 'a'];
                continue;
            }
            TrieNode* q = new TrieNode();
            p->child[c - 'a'] = q;
            p = q;
        }
        p->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p = root;
        for (const auto& c : word) {
            if (!p->child[c - 'a'])
                return false;
            p = p->child[c - 'a'];
        }
        return p->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for (const auto& c : prefix) {
            if (!p->child[c - 'a'])
                return false;
            p = p->child[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
