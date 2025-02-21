class Solution {
public:
    int numDecodings(string s) {
        vector<long> v;
        v.push_back(s[0] == '*' ? 9 : s[0] == '0' ? 0 : 1);
        if (s.length() == 1) {
            return v.back();
        }
        v.push_back(numDecodingsForLenTwoCombined(s, 1) + numDecodingsForLenOne(s, 1) * v[0]);
        for (int i = 2; i < s.length(); i++) {
            v.push_back((v[i - 2] * numDecodingsForLenTwoCombined(s, i) + v[i - 1] * numDecodingsForLenOne(s, i)) % 1000000007);
        }
        return v.back();
    }

    int numDecodingsForLenOne(const string& s, int i) {
        if (s[i] == '*') {
            return 9;
        } else if (s[i] == '0') {
            return 0;
        } else {
            return 1;
        }
    }

    // Treat this substr as a whole
    int numDecodingsForLenTwoCombined(const string& s, int i) {
        if (s[i - 1] == '0') {
            return 0;
        }
        if (isdigit(s[i - 1]) && isdigit(s[i])) {
            if (s[i] == '0') {
                return s[i - 1] < '3' ? 1 : 0;
            } else if (stoi(s.substr(i - 1, 2)) <= 26) {
                return 1;
            } else {
                return 0;
            }
        } else if (isdigit(s[i - 1])) {
            if (s[i - 1] == '0') {
                return 0;
            } else if (s[i - 1] < '2') {
                return 9;
            } else if (s[i - 1] == '2') {
                return 6;
            } else {
                return 0;
            }
        } else if (isdigit(s[i])) {
            if (s[i] <= '6') {
                return 2;
            } else {
                return 1;
            }
        } else {
            return 15;
        }
    }
};
