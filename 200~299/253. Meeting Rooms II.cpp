/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& in) {
        map<int, int> m;
        int result = 0;
        int res = 0;
        for (int i = 0; i < in.size(); ++i) {
            if (m.find(in[i].start) == m.end())
                m[in[i].start] = 1;
            else
                m[in[i].start]++;
            if (m.find(in[i].end) == m.end())
                m[in[i].end] = -1;
            else
                m[in[i].end]--;
        }
        for (map<int, int> :: iterator it = m.begin(); it != m.end(); ++it) {
            res += it->second;
            result = max(result, res);
        }
        return result;
    }
};
