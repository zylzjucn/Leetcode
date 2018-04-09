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
    vector<Interval> insert(vector<Interval>& ins, Interval t) {
        vector<Interval> res;
        if (ins.size() == 0) {
            res.push_back(t);
            return res;
        }
        int i = 0;
        for (; i < ins.size() && t.start > ins[i].end; res.push_back(ins[i]), ++i);
        if (i < ins.size())
            t.start = min(ins[i].start, t.start);
        for (; i < ins.size() && ins[i].start <= t.end; ++i);
        t.end = max(ins[i - 1].end, t.end);
        res.push_back(t);
        for (; i < ins.size(); res.push_back(ins[i]), ++i);
        return res;
    }
};
