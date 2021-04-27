class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> se;
        for (const auto& s : A) {
            string s1;
            string s2;
            int i = 0;
            for (; i < s.length() - 1; i += 2) {
                s1.append(1, s[i]);
                s2.append(1, s[i + 1]);
            }
            if (i < s.length())
                s1.append(1, s[i]);
            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());
            se.insert(s1 + s2);
        }
        return se.size();
    }
};
