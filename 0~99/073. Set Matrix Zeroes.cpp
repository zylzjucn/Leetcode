class Solution {
public:
    void setZeroes(vector<vector<int>>& v) {
        int i, j, flag = 1;
        for (i = 0; i < v.size(); i++) {
            if (v[i][0] == 0)
                flag = 0;
            for (j = 1; j < v[0].size(); j++)
                if(v[i][j] == 0)
                    v[i][0] = v[0][j] = 0;
        }
        for (i = v.size() - 1; i >= 0; i--) {
            for (j = v[0].size() - 1; j >= 1; j--)
                if (v[i][0] == 0 || v[0][j] == 0)
                    v[i][j] = 0;
            if(flag == 0)
                v[i][0] = 0;
        }  
    }
};
