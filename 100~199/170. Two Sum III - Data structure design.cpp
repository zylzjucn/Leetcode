class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        m[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int val) {
        for (auto it = m.begin(); (2 * it->first <= val) && it != m.end(); it++) {
            if ((2 * it->first == val && it->second > 1) || (2 * it->first != val && m.find(val - it->first) != m.end()))
                return true;
        }
        return false;
    }
    
private:
    map<int, int> m;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */
