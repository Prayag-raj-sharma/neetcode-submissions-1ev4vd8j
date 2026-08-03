class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0];
        int currSum = 0;

        for(int i = 0; i < n; i++) {
            currSum = nums[i] + max(currSum, 0);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};
