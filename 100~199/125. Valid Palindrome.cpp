class Solution {
public:
    bool isPalindrome(string s) {
        stack<char> c;
        int i;
        for (i = 0; i < s.size(); i++) {
            if (s[i] > 96 && s[i] < 123)
                c.push(s[i]);
            if (s[i] > 64 && s[i] < 91)
                c.push(s[i] + 32);
            if (s[i] > 47 && s[i] < 58)
                c.push(s[i]);
        }
        for (i = 0; i < s.size(); i++) {
            if(s[i] > 96 && s[i] < 123) {
                if (s[i] == c.top())
                    c.pop();
                else
                    return false;
            }
            if (s[i] > 64 && s[i] < 91) {
                if (s[i] + 32 == c.top())
                    c.pop();
                else
                    return false;
            }
            if (s[i] > 47 && s[i] < 58) {
                if (s[i] == c.top())
                    c.pop();
                else
                    return false;
            }
        }
        return true;
    }
};
