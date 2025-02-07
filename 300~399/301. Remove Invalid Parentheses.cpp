class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        remove(res, s, '(', ')', 0, 0);
        return res;
    }

    void remove(vector<string>& res, string s, char c1, char c2, int last_i, int last_j) {
        int count = 0;
        for (int i = last_i; i < s.length(); i++) {
            if (s[i] == c1) {
                count++;
            } else if (s[i] == c2) {
                count--;
            }
            if (count >= 0) {
                continue;
            }
            for (int j = last_j; j <= i; j++) {
                if (s[j] == c2 && (j == 0 || (j > 0 && s[j - 1] != c2))) {
                    remove(res, s.substr(0, j) + s.substr(j + 1), c1, c2, i, j);
                }
            }
            return;
        }
        reverse(s.begin(), s.end());
        if (c1 == '(') {
            remove(res, s, ')', '(', 0, 0);
        } else {
            res.push_back(s);
        }
    }
};
