class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes = -1e9;

        int ones = 0;

        for(auto n: nums) {
            if(n == 1) ones++;
            else {
                maxOnes = max(maxOnes, ones);
                ones = 0;
            }
        }
        maxOnes = max(maxOnes, ones);
        return maxOnes;
    }
};