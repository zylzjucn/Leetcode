struct Node {
    int key;
    int val;
    int freq;
    Node* prev;
    Node* next;
    Node(int key, int val, int freq): key(key), val(val), freq(freq), prev(nullptr), next(nullptr) {}
};

class LFUCache {

private:
    int min_freq_;
    unordered_map<int, Node*> key_to_node_;
    unordered_map<int, pair<Node*, Node*>> freq_to_doubly_linked_list_;
    int capacity_;
    int count_;

    void addNodeToFreq(Node* node, int freq) {
        if (freq_to_doubly_linked_list_.count(freq)) {
            Node* tail = freq_to_doubly_linked_list_[freq].second;
            tail->next = node;
            node->prev = tail;
            node->next = nullptr;
            freq_to_doubly_linked_list_[freq].second = node;
        } else {
            node->prev = nullptr;
            node->next = nullptr;
            freq_to_doubly_linked_list_[freq] = make_pair(node, node);
        }
    }

    void removeNodeFromFreq(Node* node) {
        int freq = node->freq;
        if (node->prev && node->next) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        } else if (node->prev) {
            node->prev->next = nullptr;
            freq_to_doubly_linked_list_[freq].second = node->prev;
        } else if (node->next) {
            node->next->prev = nullptr;
            freq_to_doubly_linked_list_[freq].first = node->next;
        } else {
            freq_to_doubly_linked_list_.erase(freq);
            if (min_freq_ == freq) {
                min_freq_++;
            }
        }
    }

public:
    LFUCache(int capacity): min_freq_(0), count_(0), capacity_(capacity) {}
    
    int get(int key) {
        if (!key_to_node_.count(key)) {
            return -1;
        }
        Node* node = key_to_node_[key];
        int freq = node->freq;
        removeNodeFromFreq(node);
        node->freq = freq + 1;
        addNodeToFreq(node, freq + 1);
        return key_to_node_[key]->val;
    }
    
    void put(int key, int value) {
        if (key_to_node_.count(key)) {
            get(key);
            key_to_node_[key]->val = value;
        } else {
            if (count_ == capacity_) {
                Node* node = freq_to_doubly_linked_list_[min_freq_].first;
                removeNodeFromFreq(node);
                key_to_node_.erase(node->key);
                delete node;
                count_--;
            }
            min_freq_ = 1;
            count_++;
            Node* node = new Node(key, value, 1);
            key_to_node_[key] = node;
            addNodeToFreq(node, 1);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
