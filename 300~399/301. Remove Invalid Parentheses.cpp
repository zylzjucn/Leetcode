class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        remove(res, s, '(', ')', 0, 0);
        return res;
    }
    void remove(vector<string> &res, string s, char c1, char c2, int lasti, int lastj) {
        int count = 0;
        for (int i = lasti; i < s.length(); i++) {
            if (s[i] == c1)
                count++;
            else if (s[i] == c2)
                count--;
            if (count >= 0)
                continue;
            for (int j = lastj; j <= i; j++)
                if (s[j] == c2 && s[j - 1] != c2)
                    remove(res, s.substr(0, j) + s.substr(j + 1), c1, c2, i, j);
            return;
        }
        reverse(s.begin(), s.end());
        if (c1 == '(')
            remove(res, s, ')', '(', 0, 0);
        else
            res.push_back(s);
    }
};  
