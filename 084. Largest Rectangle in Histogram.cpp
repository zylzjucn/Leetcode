class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int res = 0;
        int n = h.size();
        if (n == 0)
            return 0;
        int leftWall[n];
        int rightWall[n];
        leftWall[0] = -1;
        rightWall[n - 1] = n;
        for (int i = 1; i < n; i++) {
            int j = i - 1;
            while (j >= 0 && h[j] >= h[i])
                j = leftWall[j];  // such a beautiful trick
            leftWall[i] = j;
        }
        for (int i = n - 2; i >= 0; i--) {
            int j = i + 1;
            while (j < n && h[j] >= h[i])
                j = rightWall[j];
            rightWall[i] = j;
        }
        for (int i = 0; i < n; i++)
            res = max(res, h[i] * (rightWall[i] - leftWall[i] - 1));
        return res;
    }
};
