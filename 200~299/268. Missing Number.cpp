class Solution {
public:
    int missingNumber(vector<int>& n) {
        int sum = (n.size() + 1) * n.size() / 2;
        for (int i = 0; i < n.size(); ++i)
            sum -= n[i];
        return sum;
    }
};
