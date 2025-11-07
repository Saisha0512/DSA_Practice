class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minprice = INT_MAX, maxprofit = INT_MIN;
        for (int i = 0; i < n; i ++){
            if (prices[i] < minprice){
                minprice = prices[i];
            }

            maxprofit = max(maxprofit, prices[i] - minprice);
        }

        return maxprofit;
    }
};