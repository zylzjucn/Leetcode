class Solution {
public:
    int shortestPath(vector<vector<int>>& m, int k) {
        vector<int> dirs = {-1, 0, 1, 0, -1};
        int row = m.size();
        int col = m[0].size();
        queue<tuple<int, int, int>> q;
        vector<vector<int>> past(row, vector<int>(col, INT_MAX));
        q.emplace(0, 0, 0);
        q.emplace(-1, -1, -1);
        past[0][0] = 0;
        int steps = 0;
        while (q.size() > 1) {
            int i, j, k_cur;
            tie(i, j, k_cur) = q.front();
            q.pop();
            if (i == -1) {
                steps++;
                q.emplace(-1, -1, -1);
            }
            if (i + j == row + col - 2)
                return steps;
            for (int index = 0; index < 4; index++) {
                int i_next = i + dirs[index];
                int j_next = j + dirs[index + 1];
                if (i_next < 0 || i_next == row || j_next < 0 || j_next == col)
                    continue;
                if (k_cur + m[i_next][j_next] >= past[i_next][j_next] || k_cur > k)
                    continue;
                past[i_next][j_next] = k_cur + m[i_next][j_next];
                q.emplace(i_next, j_next, past[i_next][j_next]);
            }
        }
        return -1;
    }
};
