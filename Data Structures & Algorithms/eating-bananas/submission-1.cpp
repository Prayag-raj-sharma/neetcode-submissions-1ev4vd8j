class Solution {
private:
    int isPossible(vector<int>& piles, int speed) {
        int count = 0;
        for(int i = 0; i < piles.size(); i++) {
            count += (piles[i] + speed - 1)/ speed;
        }
        return count;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while(l < r) {
            int mid = l + (r - l) / 2;
            if(isPossible(piles, mid) <= h) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l; 
    }
};
