class Solution {
public:
    int minTotalDistance(vector<vector<int>>& m) {
        vector<int> x(m[0].size(), 0);
        vector<int> y(m.size(), 0);
        for (int i = 0; i < m.size(); i++)
            for (int j = 0; j < m[0].size(); j++) {
                x[j] += m[i][j];
                y[i] += m[i][j];
            }
        return get_distance(x) + get_distance(y);
    }
    
private:
    int get_distance(vector<int> v) {
        int i = 0;
        int j = v.size() - 1;
        int left = v[0];
        int right = v.back();
        int stepl = 0;
        int stepr = 0;
        while (i < j) {
            if (left <= right) {
                stepl += left;
                i++;
                left += v[i];
            }
            else if (left > right) {
                stepr += right;
                j--;
                right += v[j];
            }
        }
        return stepl + stepr;
    }
};
