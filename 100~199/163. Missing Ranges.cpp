class Solution {
public:
    vector<string> findMissingRanges(vector<int>& n, int lower, int upper) {
        vector<string> v;
        if (n.size() == 0) {
            v.push_back(group(lower, upper));
            return v;
        }
        if (n[0] != lower)
            v.push_back(group(lower, n[0] - 1));
        for (int i = 1; i < n.size(); i++)
            if (n[i] != n[i - 1] + 1 && n[i] != n[i - 1])
                v.push_back(group(n[i - 1] + 1, n[i] - 1));
        if (n.back() != upper)
            v.push_back(group(n.back() + 1, upper));
        return v;
    }
    string group(int start, int end) {
        if (start == end)
            return to_string(start);
        else
            return to_string(start) + "->" + to_string(end);
    }
};
