class Solution {
public:
    bool checkRecord(string s) {
        int absents = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'A') {
                absents++;
                if (absents >= 2)
                    return false;
            }
            else if (s[i] == 'L') {
                if (i + 3 <= s.length() && s.substr(i, 3) == "LLL")
                    return false;
            }
        }
        return true;
    }
};
