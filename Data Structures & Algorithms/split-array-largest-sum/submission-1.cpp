class Solution {
private:
    int isPossible(vector<int>& nums, int sum) {
        int currentSum = 0;
        int subarrays = 1;
        for(auto n : nums) {
            if(currentSum + n > sum) {
                subarrays++;
                currentSum = n;
            } else {
                currentSum += n;
            }
        }
        return subarrays;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);

        while(l < r) {
            int mid = l + (r - l) / 2;
            if(isPossible(nums, mid) <= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l; 
    }
};