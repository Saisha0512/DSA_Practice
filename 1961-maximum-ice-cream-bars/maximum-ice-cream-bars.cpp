class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxel = *max_element(costs.begin(), costs.end());
        vector<int> count(maxel + 1, 0);
        for (auto cost : costs){
            count[cost] ++;
        }

        int total = 0;
        for (int i = 0; i <= maxel; i ++){
            while (count[i] -- && coins >= i){
                coins -= i;
                total ++;
            }
        }

        return total;
    }
};