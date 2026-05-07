/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<Interval> sorted_intervals = intervals;

        // O(nlog(n))
        sort(sorted_intervals.begin(), sorted_intervals.end(),
            [](const auto& p, const auto& q) {
                return p.start < q.start;
            }
        );

        // O(n)
        for (int idx = 1; idx < sorted_intervals.size(); idx++) {
            if (sorted_intervals[idx].start < sorted_intervals[idx - 1].end) {
                return false;
            }
        }        

        return true;
    }
};
