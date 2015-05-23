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
    class cmp
    {
        public:
        bool operator()(const Interval& v1, const Interval& v2) {
            return v1.start < v2.start || (v1.start == v2.start && v1.end < v2.end);
        }
    };
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ret;
        if (intervals.size() < 2)
            return intervals;
        sort(intervals.begin(), intervals.end(), cmp());
        Interval v = intervals[0];
        for (int i = 1; i < intervals.size(); i ++) {
            if (intervals[i].start <= v.end)
                v.end = max(v.end, intervals[i].end);
            else {
                ret.push_back(v);
                v = intervals[i];
            }
        }
        ret.push_back(v);
        return ret;
    }
};
