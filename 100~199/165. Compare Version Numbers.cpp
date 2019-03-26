class Solution {
public:
    int compareVersion(string s1, string s2) {
        int i = 0;
        int j = 0;
        while (i < s1.length() || j < s2.length()) {
            int a = 0;
            int b = 0;
            while (i < s1.length() && s1[i] != '.') {
                a = 10 * a + (s1[i] - '0');
                i++;
            }
            while (j < s2.length() && s2[j] != '.') {
                b = 10 * b + (s2[j] - '0');
                j++;
            }
            if (a > b)
                return 1;
            if (a < b)
                return -1;
            i++;
            j++;
        }
        return 0;
    }
};
