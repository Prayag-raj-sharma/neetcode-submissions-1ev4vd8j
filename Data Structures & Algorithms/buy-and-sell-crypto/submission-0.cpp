class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = INT_MIN;
        int minPrice = INT_MAX;

        for(auto price: prices) {
            minPrice = min(minPrice, price);
            int profit = price - minPrice;
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit; 
    }
};
