class Solution {
public:
    vector<int> countSmaller(vector<int>& n) {
        vector<int> res(n.size(), 0);
        if (n.size() == 0)
            return res;
        vector<pair<int, int>> v;
        for (int i = 0; i < n.size(); i++)
            v.emplace_back(i, 0);
        vector<pair<int, int>> result = merge_sort(v, n);
        for (const auto& p : result)
            res[p.first] = p.second;
        return res;
    }
    vector<pair<int, int>> merge_sort(vector<pair<int, int>>& v, vector<int>& n) {
        if (v.size() == 1)
            return v;
        int mid = v.size() / 2;
        vector<pair<int, int>> vleft(v.begin(), v.begin() + mid);
        vector<pair<int, int>> vright(v.begin() + mid, v.end());
        vleft = merge_sort(vleft, n);
        vright = merge_sort(vright, n);
        return merge(vleft, vright, n);
    }
    vector<pair<int, int>> merge(vector<pair<int, int>>& a, vector<pair<int, int>>& b, vector<int>& n) {
        vector<pair<int, int>> res;
        int i = 0;
        int j = 0;
        int count_right = 0;
        while (i < a.size() && j < b.size()) {
            if (n[a[i].first] <= n[b[j].first]) {
                res.emplace_back(a[i].first, a[i].second + count_right);
                i++;
            }
            else {
                res.push_back(b[j]);
                j++;
                count_right++;
            }
        }
        while (i < a.size()) {
            res.emplace_back(a[i].first, a[i].second + count_right);
            i++;
        }
        while (j < b.size()) {
            res.push_back(b[j]);
            j++;
            count_right++;
        }
        return res;
    }
};
