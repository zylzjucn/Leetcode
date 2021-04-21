class Solution {
public:
    int minSwaps(vector<int>& v) {
        int sum = 0;
        for (const auto val : v)
            if (val == 1)
                sum++;
        int i = 0;
        int cur_sum = 0;
        for (; i < sum; i++)
            if (v[i] == 1)
                cur_sum++;
        int max_cur_sum = cur_sum;
        for (int i = 0; i + sum < v.size(); i++) {
            if (v[i] == 1)
                cur_sum--;
            if (v[i + sum] == 1)
                cur_sum++;
            max_cur_sum = max(max_cur_sum, cur_sum);
        }
        return sum - max_cur_sum;
    }
};
