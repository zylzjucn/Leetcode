class Solution {
public:
    int firstUniqChar(string s) {
        int a[256] = {0};
        for (int i = 0; i < s.length(); ++i)
            a[s[i]]++;
        for (int i = 0; i < s.length(); ++i)
            if (a[s[i]] == 1)
                return i;
        return -1;
    }
};
