struct DBListNode {
    DBListNode* left;
    DBListNode* right;
    int val;
    int k;
    DBListNode(int _k, int _val): left(nullptr), right(nullptr), k(_k), val(_val) {}
};

class LRUCache {
    int capacity = 0;
    int count = 0;
    unordered_map<int, DBListNode*> m;
    DBListNode* head = new DBListNode(0, 0);
    DBListNode* tail = head;
    
public:
    LRUCache(int n) {
        capacity = n;
    }
    
    int get(int key) {
        if (!m.count(key))
            return -1;
        DBListNode* cur = m[key];
        if (cur == tail)
            return cur->val;
        if (cur == head) {
            head = cur->right;
            head->left = nullptr;
            cur->right = nullptr;
            cur->left = tail;
            tail->right = cur;
            tail = cur;
            return cur->val;
        }
        DBListNode* l = cur->left;
        DBListNode* r = cur->right;
        l->right = r;
        r->left = l;
        tail->right = cur;
        cur->left = tail;
        cur->right = nullptr;
        tail = cur;
        return cur->val;
    }
    
    void put(int key, int value) {
        if (count == 0) {
            DBListNode* cur = head;
            cur->k = key;
            cur->val = value;
            count++;
            m[key] = cur;
        }
        else if (m.count(key)) {
            DBListNode* cur = m[key];
            cur->val = value;
            if (cur == tail)
                return;
            if (cur == head) {
                head = cur->right;
                head->left = nullptr;
                cur->right = nullptr;
                cur->left = tail;
                tail->right = cur;
                tail = cur;
                return;
            }
            DBListNode* l = cur->left;
            DBListNode* r = cur->right;
            l->right = r;
            r->left = l;
            tail->right = cur;
            cur->left = tail;
            cur->right = nullptr;
            tail = cur;
        }
        else {
            DBListNode* cur = new DBListNode(key, value);
            tail->right = cur;
            cur->left = tail;
            tail = cur;
            m[key] = cur;
            count++;
            if (count > capacity) {
                DBListNode* p = head;
                head = head->right;
                head->left = nullptr;
                m.erase(p->k);
                delete p; // test
                count--;
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
