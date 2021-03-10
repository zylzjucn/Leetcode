class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int res = 0;
        vector<int> v(121, 0);
        for (const auto& age :ages)
            v[age]++;
        for (int i = 1; i < v.size(); i++)
            for (int j = 1; j < v.size(); j++) {
                if (request(i, j)) {
                    if (i != j)
                        res += v[i] * v[j];
                    else
                        res += v[i] * (v[i] - 1);
                }
            }
        return res;
    }
    
    bool request(int age1, int age2) {
        if (age2 <= age1 / 2 + 7)
            return false;
        if (age2 > age1)
            return false;
        if (age2 > 100 && age1 < 100)
            return false;
        return true;
    }
};
