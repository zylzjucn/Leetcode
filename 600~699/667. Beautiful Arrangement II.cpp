class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        int left = 1;
        int right = n;
        while (k > 0) {
            res.push_back(left++);
            k--;
            if (k == 0)
                break;
            res.push_back(right--);
            k--;
        }
        if (res.size() % 2 != 0)
            while (left <= right)
                res.push_back(left++);
        else
            while (left <= right)
                res.push_back(right--);
        return res;
    }
};
