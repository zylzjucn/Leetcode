class Solution {
public:
    vector<int> diStringMatch(string s) {
        int start = 0;
        int end = s.length();
        vector<int> res;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'I')
                res.push_back(start++);
            else
                res.push_back(end--);
        }
        res.push_back(start);
        return res;
    }
};
