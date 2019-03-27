class Solution {
public:
    int threeSumClosest(vector<int>& n, int t) {
        if (n.size() < 3)
            return 0;
        int res = n[0] + n[1] + n[2];
        int diff = abs(res - t);
        sort(n.begin(), n.end());
        for (int i = 0; i < n.size(); ++i) {
            int j = i + 1;
            int k = n.size() - 1;
            while (j < k) {
                if (abs(n[i] + n[j] + n[k] - t) < diff) {
                    diff = abs(n[i] + n[j] + n[k] - t);
                    res = n[i] + n[j] + n[k];
                }
                if (n[i] + n[j] + n[k] > t) {
                    k--;
                }
                else {
                    j++;
                }
            }
        }
        return res;
    }
};
