class Solution {
public:
    int trap(vector<int>& h) {
        int res = 0;
        if (h.size() == 0)
            return res;
        vector<int> left = maxFromLeft(h);
        vector<int> right = maxFromRight(h);
        for (int i = 1; i < h.size() - 1; i++)
            res += max(min(left[i], right[h.size() - i - 1]) - h[i], 0);
        return res;
    }
    vector<int> maxFromLeft(vector<int>& h) {
        vector<int> res;
        res.push_back(0);
        int result = 0;
        for (int i = 1; i < h.size(); i++) {
            result = max(result, h[i - 1]);
            res.push_back(result);
        }
        return res;
    }
    vector<int> maxFromRight(vector<int>& h) {
        vector<int> res;
        res.push_back(0);
        int result = 0;
        for (int i = h.size() - 2; i > 0; i--) {
            result = max(result, h[i + 1]);
            res.push_back(result);
        }
        return res;
    }
};
