class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        for (const auto& c : p)
            v2[c - 'a']++;
        int count = 0;
        int start = 0;
        int end = 0;
        while (end < s.length()) {
            while (v1[s[start] - 'a'] > v2[s[start] - 'a']) {
                v1[s[start] - 'a']--;
                start++;
            }
            if (count < p.length()) {
                v1[s[end] - 'a']++;
                if (v1[s[end] - 'a'] <= v2[s[end] - 'a'])
                    count++;
                end++;
            }
            else {
                if (end - start == p.length()) {
                    res.push_back(start);
                }
                if (v1[s[start] - 'a'] <= v2[s[start] - 'a'])
                    count--;
                v1[s[start] - 'a']--;
                start++;
            }
        }
        if (end - start == count && count == p.length())
            res.push_back(start);
        return res;
    }
};
