class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> res;
        for (int i = 0; i <= s.length(); i++)
            if (i == s.length() || s[i] == 'I')
                for (int j = i + 1, len = res.size(); j > len; j--)
                    res.push_back(j);
        return res;
    }
};
