class Solution {
public:
    int divisibleTripletCount(vector<int>& nums, int d) {
        vector<int> v(d, 0);
        for (const auto& num : nums) {
            v[num % d]++;
        }
        int res = 0;
        for (int i = 0; i < d; i++) {
            int count_i = v[i];
            for (int j = i; j < d; j++) {
                int count_j = i == j ? v[j] - 1 : v[j];
                int k = (i + j == 0 || i + j == d) ? 0 : d - (i + j) % d;
                int cur = 0;
                if (k > j) {
                    cur = count_i * count_j * v[k];
                    if (i == j) {
                        cur /= 2;
                    }
                } else if (k == j) {
                    cur = count_i * count_j * (count_j - 1) / 2;
                    if (i == j) {
                        cur /= 3;
                    }
                }
                res += cur;
            }
        }
        return res;
    }
};
