class Solution {
private:
    int isPossible(vector<int>& wt, int cap) {
        int days = 1;
        int currLoad = 0;

        for(auto w: wt) {
            if(w + currLoad > cap) {
                days++;
                currLoad = 0;
            }
            currLoad += w;
        }
        return days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);

        while(l < r) {
            int mid = l + (r - l) / 2;
            if(isPossible(weights, mid) <= days) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;  
    }
};