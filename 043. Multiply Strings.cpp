class Solution {
public:
    string multiply(string n1, string n2) {
        string s(n1.size() + n2.size(), '0');
        int i, j, carry = 0, temp = 0;
        for (i = n1.size() - 1; i >= 0; i--) {
            carry = 0;
            for (j = n2.size() - 1; j >= 0; j--) {
                temp = (n1[i] - '0') * (n2[j] - '0') + carry + s[i + j + 1] - '0';
                s[i + j + 1] = temp % 10 + '0';
                carry = temp / 10;
            }
            s[i] += carry;
        }
        if (s[0] == '0')
            s = s.substr(1);
        if (s[0] == '0')
            s = (1,'0');
        return s;
    }
};
