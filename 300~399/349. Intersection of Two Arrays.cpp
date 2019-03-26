class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> s1;
        unordered_set<int> s2;
        for (const auto& n : nums1)
            s1.insert(n);
        for (const auto& n : nums2)
            if (s1.find(n) != s1.end())
                s2.insert(n);
        for (auto it = s2.begin(); it != s2.end(); it++)
            res.push_back(*it);
        return res;
    }
};
