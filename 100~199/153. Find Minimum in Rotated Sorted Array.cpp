class Solution {
public:
    int findMin(vector<int>& n) {
        int i = 0, j = n.size() - 1, m;
        while (i < j && n[i] > n[j]) {
            m = (i + j) / 2;
            if(n[m] >= n[i])
                i = m + 1;
            else
                j = m;
        }
        return n[i];
    }
};
