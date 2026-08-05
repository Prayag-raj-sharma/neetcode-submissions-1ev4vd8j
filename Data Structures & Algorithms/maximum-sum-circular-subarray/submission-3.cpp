class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int currMaxSum = 0, currMinSum = 0;
        int maxSum = nums[0], minSum = nums[0];

        for(auto num: nums) {
            totalSum += num;

            currMaxSum = max(num, num + currMaxSum);
            maxSum = max(maxSum, currMaxSum);

            currMinSum = min(num, num + currMinSum);
            minSum = min(minSum, currMinSum);
        }

        if(maxSum < 0) return maxSum;

        return max(maxSum, totalSum - minSum); 
    }
};