class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string> res;
        vector<int> v(26, 0);
        for (const auto& s : B) {
            vector<int> b = build(s);
            for (int i = 0; i < 26; i++)
                v[i] = max(v[i], b[i]);
        }
        for (const auto& s : A) {
            vector<int> a = build(s);
            int i = 0;
            for (; i < 26; i++)
                if (a[i] < v[i])
                    break;
            if (i == 26)
                res.push_back(s);
        }
        return res;
    }
    
    vector<int> build(string s) {
        vector<int> tmp(26, 0);
        for (const auto& c : s)
            tmp[c - 'a']++;
        return tmp;
    }
};
