class Solution {
public:
    int minSubArrayLen(int s, vector<int>& n) {
        if (n.size() == 0)
            return 0;
        int start = 0, end = 0, len = n.size() + 1, sum = n[0];
        while (end != n.size() - 1 || sum >= s) {
            if (sum >= s) {
                len = min(len, end - start + 1);
                sum -= n[start];
                start++;
            }
            else {
                end++;
                sum += n[end];
            }
        }
        return len > n.size() ? 0 : len;
    }
};
