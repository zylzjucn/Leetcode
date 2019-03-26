class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int left = 0;
        int right = n - 1;
        int up = 0;
        int down = n - 1;
        int i = 0;
        int j = 0;
        int p = 1;
        while (p <= n * n) {
            for (; j <= right; j++)
                res[i][j] = p++;
            up++;
            j--;
            i++;
            for (; i <= down; i++)
                res[i][j] = p++;
            right--;
            i--;
            j--;
            for (; j >= left; j--)
                res[i][j] = p++;
            down--;
            j++;
            i--;
            for (; i >= up; i--)
                res[i][j] = p++;
            left++;
            i++;
            j++;
        }
        return res;
    }
};
