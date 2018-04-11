class Solution {
public:
    int findPeakElement(vector<int>& n) {
        int i = 0;
        if (n.size() == 1)
            return 0;
        for (; i < n.size() - 1; ++i) {
            if (i == 0 && n[0] > n[1])
                return 0;
            if (n[i] > n[i - 1] && n[i] > n[i + 1])
                break;
        }
        return i;
    }
};
