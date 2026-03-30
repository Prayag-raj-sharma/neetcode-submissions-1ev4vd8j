class Solution {
private:
    static bool comp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int count = 1;
        sort(intervals.begin(), intervals.end(), comp);

        int lastMeetEndTime = intervals[0][1];

        for(int i = 1; i < n; i++) {
            if(intervals[i][0] >= lastMeetEndTime) {
                count++;
                lastMeetEndTime = intervals[i][1];
            }
        }
        return n - count;
    }
};
