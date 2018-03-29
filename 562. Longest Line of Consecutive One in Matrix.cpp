class Solution {
public:
    int longestLine(vector<vector<int>>& n) {
        if (n.size() == 0) {
            return 0;
        }
        int res = 0, i = 0, j = 0;
        for (; i < n.size(); i++) {
            res = max(res, hor(n, i));
            res = max(res, dia(n, i, j));
            res = max(res, ant(n, i, j));
        }
        i = 0;
        for (j = 0; j < n[0].size(); j++) {
            res = max(res, ver(n, j));
            res = max(res, dia(n, i ,j));
        }
        i = n.size() - 1;
        for (j = 0; j < n[0].size(); j++) 
            res = max(res, ant(n, i, j));
        return res;
    }
    
    int hor(vector<vector<int>>& n, int i) {
        int lmax = 0, l = 0;
        for (int k = 0; k < n[0].size(); k++) {
            if (n[i][k] == 1)
                l++;
            else {
                lmax = max(lmax, l);
                l = 0;
            }
        }
        return max(lmax, l);
    }
    int ver(vector<vector<int>>& n, int j) {
        int lmax = 0, l = 0;
        for (int k = 0; k < n.size(); k++) {
            if (n[k][j] == 1)
                l++;
            else {
                lmax = max(lmax, l);
                l = 0;
            }
        }
        return max(lmax, l);
    }
    int dia(vector<vector<int>>& n, int i, int j) {
        int lmax = 0, l = 0;
        for (int k = 0; i + k < n.size() && j + k < n[0].size(); k++) {
            if (n[i + k][j + k] == 1)
                l++;
            else {
                lmax = max(lmax, l);
                l = 0;
            }
        }
        return max(lmax, l);
    }
    int ant(vector<vector<int>>& n, int i, int j) {
        int lmax = 0, l = 0;
        for (int k = 0; i - k >= 0 && j + k < n[0].size(); k++) {
            if (n[i - k][j + k] == 1)
                l++;
            else {
                lmax = max(lmax, l);
                l = 0;
            }
        }
        return max(lmax, l);
    }
};
