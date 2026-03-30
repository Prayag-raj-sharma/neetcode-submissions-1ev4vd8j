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
        return a.start < b.start;
    }
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), comp);
        priority_queue<int, vector<int>, greater<int>> minHeap;


        for(auto i: intervals) { 
            if(!minHeap.empty() && minHeap.top() <= i.start) {
                minHeap.pop();
            }
            minHeap.push(i.end);
        }
        return minHeap.size();  
    }
};
