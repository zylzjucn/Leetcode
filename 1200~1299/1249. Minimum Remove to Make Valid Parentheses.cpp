class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string s1;
        int count = 0;
        for (const auto c : s) {
            if (c == '(') {
                count++;
                s1.append(1, c);
            }
            else if (c == ')') {
                if (count > 0) {
                    count--;
                    s1.append(1, c);
                }
            }
            else
                s1.append(1, c);
        }
        string s2;
        count = 0;
        for (int i = s1.length() - 1; i >= 0; i--) {
            if (s1[i] == ')') {
                count++;
                s2.append(1, s1[i]);
            }
            else if (s1[i] == '(') {
                if (count > 0) {
                    count--;
                    s2.append(1, s1[i]);
                }
            }
            else
                s2.append(1, s1[i]);
        }
        reverse(s2.begin(), s2.end());
        return s2;
    }
};
