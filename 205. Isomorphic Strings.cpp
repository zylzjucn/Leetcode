class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char c1[256]={0}, c2[256]={0};
        for (int i = 0; i < s.length(); i++) {
            if (c1[s[i]] != c2[t[i]])
                return false;
            c1[s[i]] = c2[t[i]] =  i + 1;
        }
        return true;
    }
};
