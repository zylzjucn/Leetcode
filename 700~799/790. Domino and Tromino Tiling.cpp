class Solution {
public:
    int numTilings(int n) {
        int mod = pow(10, 9) + 7;
        // vector<int> f0 = {1, 1};
        // vector<int> f1 = {0, 0};
        // vector<int> f2 = {0, 0};
        long f0pre = 1;
        long f0 = 1;
        long f1 = 0;
        for (int i = 2; i <= n; i++) {
            long tmp = f0;
            f0 = (f0 + f0pre + 2 * f1) % mod;
            f1 = (f1 + f0pre) % mod;
            f0pre = tmp;
            
            // f1.push_back((f0[i - 2] + f1[i - 1]) % mod);
            // f0.push_back((f0[i - 2] + f0[i - 1] + 2 * f1[i - 1]) % mod);
        }
        return f0;
    }
};
