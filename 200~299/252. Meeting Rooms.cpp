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
    bool canAttendMeetings(vector<Interval>& in) {
        sort(in.begin(), in.end(), [](Interval a, Interval b) {return a.start < b.start;});
        for (int i = 1; i < in.size(); ++i)
            if (in[i - 1].end > in[i].start)
                return false;
        return true;
    }
};
