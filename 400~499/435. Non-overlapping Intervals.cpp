class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        sort(in.begin(), in.end(), [](vector<int> a, vector<int> b) {return a[0] < b[0]; });
        int res = 0;
        int pre = 0;
        for (int i = 1; i < in.size(); i++) {
            if (in[i][0] < in[pre][1]) {
                if (in[i][1] < in[pre][1])
                    pre = i;
                res++;
            }
            else
                pre = i;
        }
        return res;
    }
};
