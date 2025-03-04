class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int count = 0;
        int i = 0; 
        while (i < s.length()) {
            if (s[i] == ')') {
                if (count == 0) {
                    s.erase(i, 1);
                    continue;
                } else {
                    count--;
                }
            } else if (s[i] == '(') {
                count++;
            }
            i++;
        }
        i = s.length() - 1;
        count = 0;
        while (i >= 0) {
            if (s[i] == '(') {
                if (count == 0) {
                    s.erase(i, 1);
                } else {
                    count--;
                }
            } else if (s[i] == ')') {
                count++;
            }
            i--;
        }
        return s;
    }
};
