// TOP - DOWN APPROACH : 
class Solution {
    vector<int> dp;
    // dp[i] = minimum cost required to cover first n travel days

    int buy(vector<int> &days, vector<int> &costs, int n){
        // base case
        if (n == 0){
            return 0;
        }

        // check dp
        if (dp[n] != -1){
            return dp[n];
        }

        // recursive case
        int tempans = INT_MAX;
        // trying to buy a ticket such that its validity ends on (n - 1)th day
        for (int i = 0; i < costs.size(); i ++){
            int currdays;
            if (i == 0){
                currdays = 1;
            }
            else if (i == 1){
                currdays = 7;
            }
            else {
                currdays = 30;
            }

            // ignoring all those days for which this ticket is bought
            int j = n - 2;
            while (j >= 0 && days[j] >= days[n - 1] - currdays + 1){
                j --;
            }

            tempans = min(tempans, costs[i] + buy(days, costs, j + 1));
        }

        return dp[n] = tempans;
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        dp.resize(n + 1, -1);

        return buy(days, costs, n);
    }
};