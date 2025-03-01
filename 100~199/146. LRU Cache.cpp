struct Node {
    Node* prev;
    Node* next;
    int key;
    int val;
    Node(int key, int val): prev(nullptr), next(nullptr), key(key), val(val) {}
    Node(int key, int val, Node* prev, Node* next): prev(prev), next(next), key(key), val(val) {}
};

class LRUCache {
private:
    int count_;
    int capacity_;
    unordered_map<int, Node*> m;
    Node* head;
    Node* tail;

public:
    LRUCache(int capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        count_ = 0;
        capacity_ = capacity;
    }
    
    int get(int key) {
        if (m.count(key)) {
            Node* node = m[key];
            node->next->prev = node->prev;
            node->prev->next = node->next;
            node->prev = tail->prev;
            node->next = tail;
            tail->prev->next = node;
            tail->prev = node;
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // if exists
        if (m.count(key)) {
            get(key);
            m[key]->val = value;
        } else {
            Node* node = new Node(key, value, tail->prev, tail);
            m[key] = node;
            tail->prev->next = node;
            tail->prev = node;
            count_++;
            if (count_ > capacity_) {
                count_--;
                Node* old_head = head->next;
                old_head->next->prev = head;
                head->next = old_head->next;
                m.erase(old_head->key);
                delete old_head;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
