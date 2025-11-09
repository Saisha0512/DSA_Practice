class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minbuy = INT_MAX, maxprofit = 0;
        for (int i = 0; i < n; i ++){
            if (prices[i] < minbuy){
                minbuy = prices[i];
            }

            maxprofit = max(maxprofit, prices[i] - minbuy);
        }

        return maxprofit;
    }
};