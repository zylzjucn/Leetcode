class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& n, int k) {
        vector<int> res(3, 0);
        vector<int> v;
        int tmp = 0;
        for (int i = 0; i <= n.size() - k; i++) {
            if (i == 0)
                for (int j = 0; j < k; j++)
                    tmp += n[j];
            else
                tmp += n[i + k - 1] - n[i - 1];
            v.push_back(tmp);
        }
        vector<int> left(v.size(), 0);
        vector<int> right(v.size(), 0);
        tmp = 0;
        for (int i = k; i < v.size() - k; i++) {
            if (v[i - k] > tmp) {
                tmp = v[i - k];
                left[i] = i - k;
            }
            else
                left[i] = left[i - 1];
        }
        tmp = 0;
        for (int i = v.size() - k - 1; i >= k; i--) {
            if (v[i + k] >= tmp) {
                tmp = v[i + k];
                right[i] = i + k;
            }
            else
                right[i] = right[i + 1];
        }
        int sum = 0;
        for (int i = k; i < v.size() - k; i++) {
            if (v[left[i]] + v[i] + v[right[i]] > sum) {
                sum = v[left[i]] + v[i] + v[right[i]];
                res[0] = left[i];
                res[1] = i;
                res[2] = right[i];
            }
        }
        return res;
    }
};
