class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& n1, vector<int>& n2) {
        vector<int> res;
        int i = 0, j = 0;
        for (; i < n1.size(); i++) {
            for (j = 0; n2[j] != n1[i]; j++);
            for (; j < n2.size() && n2[j] <= n1[i]; j++);
            if (j < n2.size())
                res.push_back(n2[j]);
            else
                res.push_back(-1);
        }
        return res;
    }
};
