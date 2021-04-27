class LFUCache {
    
private:
    int count = 0;
    int capacity = 0;
    int min_freq = 0;
    unordered_map<int, pair<int, int>> key_to_val_freq;
    unordered_map<int, list<int>> freq_lists;
    unordered_map<int, list<int>::iterator> key_to_it;
    
public:
    LFUCache(int n) {
        capacity = n;
    }
    
    int get(int key) {
        if (!key_to_val_freq.count(key))
            return -1;
        
        freq_lists[key_to_val_freq[key].second].erase(key_to_it[key]);
        key_to_val_freq[key].second++;
        freq_lists[key_to_val_freq[key].second].push_back(key);
        key_to_it[key] = --freq_lists[key_to_val_freq[key].second].end();
        
        if (freq_lists[min_freq].empty())
            min_freq++;
        
        return key_to_val_freq[key].first;
    }
    
    void put(int key, int value) {
        if (capacity <= 0)
            return;
        int old_val = get(key);
        if (old_val != -1) {
            key_to_val_freq[key].first = value;
            return;
        }
        
        if (count >= capacity) {
            int del_key = freq_lists[min_freq].front();
            key_to_val_freq.erase(del_key);
            key_to_it.erase(del_key);
            freq_lists[min_freq].pop_front();
            count--;
        }
        
        freq_lists[1].push_back(key);
        key_to_val_freq[key] = {value, 1};
        key_to_it[key] = --freq_lists[1].end();
        min_freq = 1;
        count++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
