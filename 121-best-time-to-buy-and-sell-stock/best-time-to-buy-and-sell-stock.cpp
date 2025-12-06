class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = prices[0], maxprofit = 0;

        for (int i = 1; i < n; i ++){
            // If the current element is less than the last bought stock then we updated the value : 
            if (prices[i] < buy){
                buy = prices[i];
            }
            else {
                maxprofit = max(maxprofit, prices[i] - buy);
            }
        }

        return maxprofit;
    }
};