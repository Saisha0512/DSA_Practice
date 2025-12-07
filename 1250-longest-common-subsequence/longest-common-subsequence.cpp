class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.size(), m = t.size();

        // DP Vector : 
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Iterate for the length of the strings : 
        for (int i = 1; i <= n; i ++){
            for (int j = 1; j <= m; j ++){
                // If the current characters of both the strings match : 
                if (s[i - 1] == t[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }
};