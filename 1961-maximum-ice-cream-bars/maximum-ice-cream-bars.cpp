class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        sort(costs.begin(), costs.end());

        int total = 0, i = 0;
        while (i < n && coins >= costs[i]){
            coins -= costs[i];
            total ++;
            i ++;
        }

        return total;
    }
};