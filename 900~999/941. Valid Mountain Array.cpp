class Solution {
public:
    bool validMountainArray(vector<int>& v) {
        if (v.size() < 3)
            return false;
        int big = v[0];
        int i = 1;
        for (; i < v.size(); i++) {
            if (big < v[i])
                big = v[i];
            else
                break;
        }
        for (; i < v.size(); i++) {
            if (v[i - 1] <= v[i])
                return false;
        }
        if (big == v[0] || big == v[v.size() - 1])
            return false;
        return true;
    }
};
