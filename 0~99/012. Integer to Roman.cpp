class Solution {
public:
    string intToRoman(int n) {
        string a[] = {"", "M", "MM", "MMM"};
        string b[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string c[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string d[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return a[n / 1000] + b[(n / 100) % 10] + c[(n / 10) % 10] + d[n % 10];
    }
};
