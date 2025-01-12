class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int res = 0;
        map<int, int> m;
        for (const auto& interval : intervals) {
            m[interval[0]]++;
            m[interval[1]]--;
        }
        int cur = 0;
        for (const auto& p : m) {
            cur += p.second;
            res = max(res, cur);
        }
        return res;
    }
};
