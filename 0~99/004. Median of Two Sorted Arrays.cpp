class Solution {
public:
    double findMedianSortedArrays(vector<int>& n1, vector<int>& n2) {
        if (n1.size() > n2.size())
            return findMedianSortedArrays(n2, n1);
        int i1 = 0;
        int i2 = n1.size();
        while (i1 <= i2) {
            int i = (i1 + i2) / 2;
            int j = (n1.size() + n2.size() + 1) / 2 - i;
            if (i > 0 && j < n2.size() && n1[i - 1] > n2[j])
                i2 = i - 1;
            else if (i < n1.size() && j > 0 && n2[j - 1] > n1[i])
                i1 = i + 1;
            else {
                int maxleft;
                if (i == 0)
                    maxleft = n2[j - 1];
                else if (j == 0)
                    maxleft = n1[i - 1];
                else
                    maxleft = max(n1[i - 1], n2[j - 1]);
                if ((n1.size() + n2.size()) % 2 != 0)
                    return (double) maxleft;
                int minright;
                if (i >= n1.size())
                    minright = n2[j];
                else if (j >= n2.size())
                    minright = n1[i];
                else
                    minright = min(n1[i], n2[j]);
                return (double) (maxleft + minright) / 2;
            }
        }
        return -1;
    }
};
