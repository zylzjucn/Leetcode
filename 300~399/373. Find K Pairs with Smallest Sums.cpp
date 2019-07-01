class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        if (!nums1.size() || !nums2.size())
            return res;
        auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        pq.emplace(0, 0);
        while (k-- && pq.size()) {
            pair<int, int> p = pq.top();
            pq.pop();
            vector<int> v = {nums1[p.first], nums2[p.second]};
            res.push_back(v);
            if (p.first + 1 < nums1.size())
                pq.emplace(p.first + 1, p.second);
            if (p.first == 0 && p.second + 1 < nums2.size())
                pq.emplace(p.first, p.second + 1);
        }
        return res;
    }
};
