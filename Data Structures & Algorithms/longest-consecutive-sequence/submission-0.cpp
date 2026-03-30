class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;
        for(int n: st) {
            if(!st.count(n - 1)) {
                int curr = n;
                int len = 1;

                while(st.count(curr + 1)) {
                    len++;
                    curr++;  
                }
                longest = max(longest, len);
            }
        }
        return longest;
    }
};
