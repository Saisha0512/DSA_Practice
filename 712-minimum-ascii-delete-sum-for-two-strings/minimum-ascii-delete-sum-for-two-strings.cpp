class Solution {
public:
    int minimumDeleteSum(string s, string t) {
        int n = s.size(), m = t.size();

        // Calculating the total sum of ASCII characters for both the strings : 
        int sums = 0, sumt = 0;
        for (char ch : s)   sums += ch;
        for (char ch : t)   sumt += ch;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i ++){
            for (int j = 1; j <= m; j ++){
                // If the characters match : 
                if (s[i - 1] == t[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + s[i - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return (sums - dp[n][m]) + (sumt - dp[n][m]);
    }
};