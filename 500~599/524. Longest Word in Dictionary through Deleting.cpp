class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res = "";
        for (const auto& w : d) {
            int i = 0;
            int j = 0;
            while (i < s.length() && j < w.length()) {
                if (s[i] == w[j])
                    j++;
                i++;
            }
            if (j == w.length())
                if (w.length() > res.length() || (w.length() == res.length() && w < res))
                    res = w;
        }
        return res;
    }
};
