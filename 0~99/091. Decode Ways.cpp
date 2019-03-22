class Solution {
public:
    int numDecodings(string s) {
        if (s.length() == 0 || stoi(s.substr(0, 1)) == 0)
            return 0;
        if (s.length() == 1)
            return 1;
        int t1 = 1, t2 = 0, temp;
        if (stoi(s.substr(0, 2)) > 0 && stoi(s.substr(0, 2)) <= 26)
            t2 ++;
        if (stoi(s.substr(1, 1)) != 0)
            t2 ++;
        if (s.length() == 2)
            return t2;
        for (int i = 2; i < s.length(); i++) {
            temp = t1 * (stoi(s.substr(i-1, 2)) >= 10 && stoi(s.substr(i-1, 2)) <= 26) + t2 * (stoi(s.substr(i, 1)) != 0);
            t1 = t2;
            t2 = temp;
        }
        return temp;
    }
};
