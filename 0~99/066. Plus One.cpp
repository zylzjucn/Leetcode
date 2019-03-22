class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
        int n = v.size(), i = n-1;
        for(; i >= 0; --i) {
            if (v[i] == 9)
                v[i] = 0;
            else {
                v[i]++;
                return v;
            }
        }
        v[0] = 1;
        v.push_back(0);
        return v;
    }
};
