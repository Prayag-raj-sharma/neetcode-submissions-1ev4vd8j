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
private:
    static bool comp(Interval& a, Interval& b) {
        return a.end < b.end;
    }
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();

        if(n == 0 || n == 1) return true;

        sort(intervals.begin(), intervals.end(), comp);

        for(int i = 1; i < n; i++) {
            if(intervals[i].start < intervals[i - 1].end) {
                return false;
            }
        }
        return true; 
    }
};
