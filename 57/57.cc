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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ret;
        if (intervals.size() == 0) {
            ret.push_back(newInterval);
            return ret;
        }
        int insertPos = 0;
        for (int i = 0; i < intervals.size(); i ++) {
            if (intervals[i].end < newInterval.start) {
                ret.push_back(intervals[i]);
                insertPos ++;
            }
            else if (intervals[i].start > newInterval.end) {
                ret.push_back(intervals[i]);
            }
            else {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
        }
        ret.insert(ret.begin() + insertPos, newInterval);
        return ret;
    }
};
