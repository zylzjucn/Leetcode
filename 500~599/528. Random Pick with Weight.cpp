class Solution {
public:
    vector<int> v;
    Solution(vector<int>& w) {
        for (const auto& val : w) {
            if (v.empty())
                v.push_back(val);
            else
                v.push_back(v.back() + val);
        }
    }
    
    int pickIndex() {
        int x = rand() % v.back();
        auto it = upper_bound(v.begin(), v.end(), x);
        return it - v.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
