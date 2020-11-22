class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if (jobDifficulty.size() < d)
            return -1;
        vector<vector<int>> v(d + 1, vector<int>(jobDifficulty.size() + 1, INT_MAX / 2));
        v[0][0] = 0;
        for (int i = 1; i < v.size(); i++) {
            for (int j = i; j < v[0].size(); j++) {
                int maxkj = 0;
                for (int k = j; k >= i; k--) {
                    maxkj = max(maxkj, jobDifficulty[k - 1]);
                    v[i][j] = min(v[i][j], v[i - 1][k - 1] + maxkj);
                }
            }
        }
        return v.back().back();
    }
};
