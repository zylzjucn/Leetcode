class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        int rbegin = 0, cbegin = 0, rend = m.size() - 1;
        vector<int> v;
        if (rend == -1)
            return v;
        int cend = m[0].size()-1;
        while(rbegin <= rend && cbegin <= cend) {
            for (int i = cbegin; i <= cend; i++)
                v.push_back(m[rbegin][i]);
            rbegin++;
            for (int i = rbegin; i <= rend; i++)
                v.push_back(m[i][cend]);
            cend--;
            if (rbegin <= rend) {
                for (int i = cend; i >= cbegin; i--)
                    v.push_back(m[rend][i]);
                rend--;
            }
            if(cbegin <= cend) {
                for(int i = rend; i >= rbegin; i--)
                    v.push_back(m[i][cbegin]);
                cbegin++;
            }
        }
        return v;
    }
};
