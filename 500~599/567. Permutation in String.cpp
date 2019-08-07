class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> v(26, 0);
        vector<int> tmp(26, 0);
        for (const auto& c : s1)
            v[c - 'a']++;
        int start = 0;
        int end = 0;
        int count = 0;
        while (end < s2.length()) {
            if (count < end - start) {
                tmp[s2[start] - 'a']--;
                if (tmp[s2[start] - 'a'] < v[s2[start] - 'a'])
                    count--;
                start++;
            }
            else {
                if (end - start == s1.length())
                    return true;
                else {
                    tmp[s2[end] - 'a']++;
                    if (tmp[s2[end] - 'a'] <= v[s2[end] - 'a'])
                        count++;
                    end++;
                }
            }
        }
        return end - start == count && count == s1.length();
    }
};
