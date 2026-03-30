class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int area = 0, maxArea = INT_MIN;

        int l = 0, r = n - 1;
        while(l < r) {
            area = min(heights[l], heights[r]) * (r - l);
            maxArea = max(maxArea, area);

            if(heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            } 
        }
        return maxArea;
    }
};
