class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return notBiggerThan(A, K) - notBiggerThan(A, K - 1);
    }

private:
    int notBiggerThan(vector<int>& v, int K) {
        int res = 0;
        unordered_map<int, int> m;
        int start = 0;
        int end = 0;
        while (start <= end && end < v.size()) {
            if (m.count(v[end])) {
                m[v[end]]++;
                end++;
            }
            else if (m.size() < K) {
                m[v[end]]++;
                end++;
            }
            else {
                m[v[start]]--;
                if (m[v[start]] == 0)
                    m.erase(v[start]);
                start++;
                continue;
            }
            res += end - start;
        }
        return res;
    }
};
