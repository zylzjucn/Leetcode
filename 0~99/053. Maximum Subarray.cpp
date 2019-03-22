class Solution {
public:
    int maxSubArray(vector<int>& n) {
        int sum = 0, maxsum = n[0];
        for (int i=0; i < n.size(); i++) {
            sum += n[i];
            maxsum = max(maxsum, sum);
            if (sum < 0)
                sum = 0;
        }
        return maxsum;
    }
};
