class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> m;
        for (const auto c : s)
            m[c]++;
        for (const auto c : t) {
            m[c]--;
            if (m[c] == 0)
                m.erase(c);
        }
        return m.empty();
    }
};
