class Solution {
public:
    vector<string> summaryRanges(vector<int>& n) {
        vector<string> v;
        if (n.size() == 0)
            return v;
        int first = n[0];
        for (int i = 1; i < n.size(); i++)
            if (n[i]!=n[i - 1] + 1) {
                v.push_back(group(first, n[i - 1]));
                first = n[i];
            }
        v.push_back(group(first, n.back()));  // remember to do this, just like the content in the if
        return v;
    }
private:
    string group(int first, int last) {
        if (first == last)
            return to_string(first);
        else
            return to_string(first) + "->" + to_string(last);  // to_string
    }
};
