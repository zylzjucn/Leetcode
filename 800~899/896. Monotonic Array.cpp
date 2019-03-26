class Solution {
public:
    bool isMonotonic(vector<int>& v) {
        if (v.back() >= v.front()) {
            for (int i = 0; i < v.size() - 1; i++)
                if (v[i] > v[i + 1])
                    return false;
        }
        else
            for (int i = 0; i < v.size() - 1; i++)
                if (v[i] < v[i + 1])
                    return false;
        return true;
    }
};
