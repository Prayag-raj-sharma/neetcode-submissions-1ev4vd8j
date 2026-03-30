class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        int currMax = 0, currMin = 0;
        int maxSum = nums[0];
        int minSum = nums[0];

        for(auto n : nums) {
            totalSum += n;

            currMax = max(n, n + currMax);
            maxSum = max(maxSum, currMax);

            currMin = min(n, n + currMin);
            minSum = min(minSum, currMin);
        }

        if(maxSum < 0) return maxSum;

        return max(maxSum, totalSum - minSum); 
    }
};