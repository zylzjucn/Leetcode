class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m1;
        for (const auto& c : s)
            m1[c]++;
        map<int, string> m2;
        for (auto it = m1.begin(); it != m1.end(); it++)
            m2[it->second].append(1, it->first);
        string res;
        for (auto it = m2.begin(); it != m2.end(); it++)
            for (const auto& c : it->second)
                res.append(it->first, c);
        reverse(res.begin(), res.end());
        return res;
    }
};
