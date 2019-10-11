class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        unordered_map<int, int> m{{0, 1}};
        int sum = 0;
        int res = 0;
        for (const auto& x : A) {
            sum += x;
            res += m[sum - S];
            m[sum]++;
        }
        return res;
    }
};
