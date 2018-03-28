class Solution {
public:
    int minPathSum(vector<vector<int>>& v) 
    {
        int i, j;
        for (i = 0; i < v.size(); i++)
            for (j = 0; j < v[0].size(); j++)
            {
                if (i == 0 && j == 0);
                else if (i == 0 && j != 0)
                    v[i][j] += v[i][j-1];
                else if (i != 0 && j == 0)
                    v[i][j] += v[i-1][j];
                else
                    v[i][j] += min(v[i-1][j], v[i][j-1]);
            }
        return v[i-1][j-1];
    }
};
