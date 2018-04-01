class Solution {
public:
    char findTheDifference(string s, string t) {
        int dif = 0;
        int i = 0;
        for (; i < s.length(); ++i)
            dif += t[i] - s[i];
        dif += t[i];
        return dif;
    }
};
