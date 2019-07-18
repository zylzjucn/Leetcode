class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), [](vector<int> a, vector<int> b) {return a[1] < b[1]; });
        int res = 0;
        int i = 0;
        while (i < v.size()) {
            int j = i + 1;
            for (; j < v.size() && v[j][0] <= v[i][1]; j++);
            res++;
            i = j;
        }
        return res;
    }
};

