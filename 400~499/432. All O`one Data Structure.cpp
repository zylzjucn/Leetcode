struct Node {
    int freq;
    unordered_set<string> strs_;
    Node* prev;
    Node* next;
    Node(int freq, string str): freq(freq), strs_({str}), prev(nullptr), next(nullptr) {}
};

class AllOne {

private:
    unordered_map<string, Node*> string_to_node_;
    Node* min_freq_;
    Node* max_freq_;

    void addNodeInInc(int freq, Node* node, string key) {
        Node* new_node = new Node(freq, key);
        if (!node->next) {
            max_freq_ = new_node;
        } else {
            new_node->next = node->next;
            new_node->next->prev = new_node;
        }
        node->next = new_node; 
        new_node->prev = node;
    }

public:
    AllOne(): min_freq_(nullptr), max_freq_(nullptr) {}
    
    void inc(string key) {
        if (string_to_node_.count(key)) {
            Node* node = string_to_node_[key];
            int freq = node->freq;
            node->strs_.erase(key);
            if (node->next && node->next->freq == freq + 1) {
                node->next->strs_.insert(key);
            } else {
                addNodeInInc(freq + 1, node, key);
            }
            string_to_node_[key] = node->next;
            if (node->strs_.empty()) {
                if (node->prev) {
                    node->prev->next = node->next;
                } else {
                    min_freq_ = node->next;
                }
                node->next->prev = node->prev;
                delete node;
            }
        } else if (min_freq_) {
            if (min_freq_->freq > 1) {
                Node* new_node = new Node(1, key);
                new_node->next = min_freq_;
                min_freq_->prev = new_node;
                min_freq_ = new_node;
            } else {
                min_freq_->strs_.insert(key);
            }
            string_to_node_[key] = min_freq_;
        } else {
            Node* new_node = new Node(1, key);
            string_to_node_[key] = new_node;
            min_freq_ = new_node;
            max_freq_ = new_node;
        }
    }
    
    void dec(string key) {
        Node* node = string_to_node_[key];
        int freq = node->freq;
        node->strs_.erase(key);
        if (node->prev && node->prev->freq == freq - 1) {
            node->prev->strs_.insert(key);
            string_to_node_[key] = node->prev;
        } else if (freq != 1){
            Node* new_node = new Node(freq - 1, key);
            if (!node->prev) {
                min_freq_ = new_node;
            } else {
                new_node->prev = node->prev;
                new_node->prev->next = new_node;
            }
            node->prev = new_node; 
            new_node->next = node;
            string_to_node_[key] = new_node;
        } else {
            string_to_node_.erase(key);
        }
        if (node->strs_.empty()) {
            if (node->prev && node->next) {
                node->next->prev = node->prev;
                node->prev->next = node->next;
            } else if (node->prev) {
                node->prev->next = nullptr;
                max_freq_ = node->prev;
            } else if (node->next) {
                node->next->prev = nullptr;
                min_freq_ = node->next;
            } else {
                max_freq_ = nullptr;
                min_freq_ = nullptr;
            }
            delete node;
        }
    }
    
    string getMaxKey() {
        return max_freq_ ? *max_freq_->strs_.begin() : "";
    }
    
    string getMinKey() {
        return min_freq_ ? *min_freq_->strs_.begin() : "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
