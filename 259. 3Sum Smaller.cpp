class Solution {
public:
    int threeSumSmaller(vector<int>& n, int t) {
        if (n.size() < 3)
            return 0;
        sort(n.begin(), n.end());
        int i, j, k, sum = 0;
        for (i = 0; i<n.size() - 2; i++) {
            j = i + 1;
            k = n.size() - 1;
            while (j < k) {
                if(n[i] + n[j] + n[k] < t) {
                    sum += k-j;
                    j++;
                }
                else
                    k--;
            }
        }
        return sum;
    }
};
