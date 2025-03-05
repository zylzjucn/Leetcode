class RandomizedSet {

private:
    unordered_map<int, int> m;
    vector<int> v;

public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        bool present = m.count(val);
        if (!present) {
            v.push_back(val);
            m[val] = v.size() - 1;
        }
        return !present;
    }
    
    bool remove(int val) {
        bool present = m.count(val);
        if (present) {
            int i = m[val];
            v[i] = v.back();
            v.pop_back();
            m[v[i]] = i;
            m.erase(val);
        }
        return present;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
