class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = INT_MAX, maxprofit = 0;
        for (int i = 0; i < n; i ++){
            // Check for buying the current stock : 
            if (prices[i] < buy){
                buy = prices[i];
            }

            maxprofit = max(maxprofit, prices[i] - buy);
        }

        return maxprofit;
    }
};