class Solution {
public:
    double champagneTower(int poured, int row, int glass) {
        // Base Case : 
        if (poured == 0){
            return 0.0;
        }
        
        vector<vector<double>> dp(101, vector<double>(101, 0.0));
        // Pouring all the champagne into the top most glass & then dividing it equally : 
        dp[0][0] = poured;
        for (int i = 0; i <= row; i ++){
            for (int j = 0; j <= i; j ++){
                if (dp[i][j] > 1){
                    double overflow = (dp[i][j] - 1) / 2.0;
                    dp[i][j] = 1;
                    dp[i + 1][j] += overflow;
                    dp[i + 1][j + 1] += overflow;
                }
            }
        }

        return min(1.0, dp[row][glass]);
    }
};