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
    vector<Interval> merge(vector<Interval> in) {
        if (in.size() < 2)
            return in;
        sort(in.begin(), in.end(), [](Interval a, Interval b){return (a.start < b.start);});
        vector<Interval> v;
        v.push_back(in[0]);
        for(int i = 1; i < in.size(); i++) {
            if(in[i].start <= v.back().end)
                v.back().end = max(in[i].end, v.back().end);
            else
                v.push_back(in[i]);
        }
        return v;
    }  
};
