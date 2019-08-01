/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/
class Solution {
public:
    vector<Interval*> employeeFreeTime(vector<vector<Interval*>>& schedule) {
        vector<Interval*> v;
        for (const auto& vi : schedule)
            for (const auto& in : vi)
                v.push_back(in);
        sort(v.begin(), v.end(), [](Interval* a, Interval* b) {return a->start < b->start;});
        int end = v[0]->end;
        vector<Interval*> res;
        for (const auto& in : v) {
            if (in->start > end) {
                Interval* p = new Interval(end, in->start);
                res.emplace_back(p);
                end = in->end;
            }
            else
                end = max(end, in->end);
        }
        return res;
    }
};
