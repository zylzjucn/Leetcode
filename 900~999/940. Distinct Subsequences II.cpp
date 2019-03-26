class Solution {
public:
    int mod = 1000000007;
    int distinctSubseqII(string s) {
        int a[256] = {0};
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            int tmp = a[s[i]];
            a[s[i]] = sum + 1;
            sum += sum + 1 - tmp;
            if (sum < 0)
                sum += mod;
            if (sum > mod)
                sum -= mod;
        }
        return sum;
    }
};
