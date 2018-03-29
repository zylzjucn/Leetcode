class Solution {
public:
    int pivotIndex(vector<int>& n) {
        if (n.size() == 0)
            return -1;
        int sum = 0, suml = 0;
        for (int i = 0; i < n.size(); i++)
            sum += n[i];
        for (int i = 0; i < n.size(); i++) {
            if (sum == 2 * suml + n[i])
                return i;
            suml += n[i];
        }
        return -1;
    }
};
