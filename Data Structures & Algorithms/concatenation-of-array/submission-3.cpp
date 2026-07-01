class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(size * 2);
        int i = 0;
        for(auto n: nums) {
            ans[i] = nums[i];
            ans[i + size] = nums[i];
            i++;
        }
        return ans; 
    }
};