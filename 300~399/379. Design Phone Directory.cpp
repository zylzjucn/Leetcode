class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        n = maxNumbers;
        for (int i = 0; i < n; i++)
            s.insert(i);
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (s.empty())
            return -1;
        int res = *s.begin();
        s.erase(s.begin());
        return res;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return (s.count(number));
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        s.insert(number);
    }

private:
    int n;
    set<int> s;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
