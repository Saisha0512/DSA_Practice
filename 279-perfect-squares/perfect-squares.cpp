// TOP - DOWN APPROACH : 
class Solution {
    vector<int> dp;

    int square(int n){
        // base case
        if (n == 0){
            return 0;
        }

        // check dp
        if (dp[n] != -1){
            return dp[n];
        }

        // recursive case
        // looping through all the possible square on adding which we could get the current n : 
        int tempans = INT_MAX;
        for (int i = 1; i * i <= n; i ++){
            tempans = min(tempans, 1 + square(n - (i * i)));
        }

        return dp[n] = tempans;
    }

public:
    int numSquares(int n) {
        dp.resize(n + 1, -1);

        return square(n);
    }
};