class Solution {
public:
    int minDeletionSize(vector<string>& v) {
        int res = 0;
        for (int i = 0; i < v[0].length(); i++) {
            if (!issorted(v, i))
                res++;
        }
        return res;
    }
    bool issorted(vector<string>& v, int col) {
        for (int i = 1; i < v.size(); i++) {
            if (v[i][col] < v[i - 1][col])
                return false;
        }
        return true;
    }
};
