class Solution {
public:
    long long maximumSumScore(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        long long rightSum = 0;
        long long maxSum = LONG_MIN;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }

        for(int i = n - 1; i >= 0; i--) {
            rightSum += nums[i];

            maxSum = max(maxSum, max(sum, rightSum));

            sum -= nums[i];
        }
        return maxSum;
    }
};
