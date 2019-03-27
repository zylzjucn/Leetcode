class Solution {
public:
    string addStrings(string n1, string n2) {
        string res;
        if (n1.length() < n2.length())
            swap(n1, n2);
        int carry = 0;
        for (int i = n1.length() - 1, j = n2.length() - 1; i >= 0; i--, j--) {
            char c;
            if (j >= 0)
                c = n1[i] + n2[j] + carry - '0';
            else
                c = n1[i] + carry;
            if (c > '9') {
                carry = 1;
                c -= 10;
            }
            else
                carry = 0;
            res.append(1, c);
        }
        if (carry == 1)
            res.append(1, '1');
        for (int i = 0, j = res.length() - 1; i < j; i++, j--)
            swap(res[i], res[j]);
        return res;
    }
};
