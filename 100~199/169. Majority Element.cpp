class Solution {
public:
    int majorityElement(vector<int>& n) {
        int res = n[0];
        int count = 1;
        for (int i = 1; i < n.size(); i++) {
            res == n[i] ? count ++ : count --;
            if (count < 0) {
                res = n[i];
                count = 1;
            }
        }
        return res;
    }
};
