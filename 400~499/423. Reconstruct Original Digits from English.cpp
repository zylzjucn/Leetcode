class Solution {
public:
    string originalDigits(string s) {
        string res;
        int a[26] = {0};
        int b[10] = {0};
        for (int i = 0; i < s.length(); i++)
            a[s[i] - 'a']++;
        b[0] = a[25];
        b[2] = a[22];
        b[4] = a[20];
        b[6] = a[23];
        b[8] = a[6];
        b[1] = a[14] - b[0] - b[2] - b[4];
        b[3] = a[17] - b[0] - b[4];
        b[7] = a[18] - b[6];
        b[5] = a[21] - b[7];
        b[9] = a[8] - b[5] - b[6] - b[8];
        for (int i = 0; i < 10; i++)
            res.append(b[i], i + '0');
        return res;
    }
};
