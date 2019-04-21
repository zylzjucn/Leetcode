class Solution {
public:
    vector<int> findDuplicates(vector<int>& n) {
        vector<int> res;
        for (int i = 0; i < n.size(); i++) {
            int index = abs(n[i]) - 1;
            n[index] *= -1;
            if (n[index] > 0)
                res.push_back(index + 1);
        }
        return res;
    }
};
