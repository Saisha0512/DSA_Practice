class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int maxProf = 0, lastBuy = prices[0];
        for (int i = 1; i < n; i ++){
            maxProf = max(maxProf, prices[i] - lastBuy);
            lastBuy = min(lastBuy, prices[i]);
        }

        return maxProf;
        
        // TC : O(n)
        // SC : O(1)
    }
};