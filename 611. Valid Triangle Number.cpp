class Solution {
public:
    int triangleNumber(vector<int>& n) {
        sort(n.begin(), n.end());
        int i, j, k, count = 0;
        for (i = n.size() - 1; i > 1; i--) {
            j = 0;
            k = i - 1;
            while (j < k) {
                if(n[j] + n[k] > n[i]) {
                    count += k - j;
                    k--;
                }
                else
                    j++;
            }
        }
        return count;
    }
};
