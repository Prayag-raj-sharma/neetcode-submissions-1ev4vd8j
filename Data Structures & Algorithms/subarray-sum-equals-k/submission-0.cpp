class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> prefixSumMap;

        prefixSumMap[0] = 1;

        int count = 0;
        int currSum = 0;

        for(int i = 0; i < n; i++) {
            currSum += nums[i];

            int needed = currSum - k;
            count += prefixSumMap[needed];

            prefixSumMap[currSum]++;
        }
        return count;  
    }
};