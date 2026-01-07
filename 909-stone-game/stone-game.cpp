class Solution {
    int takeStone(vector<int> &piles, int i, int j, vector<vector<int>> &dp){
        // Base Case : 
        if (j < i){
            return 0;
        }
        if (i == j){
            return piles[i];
        }

        // Check DP : 
        if (dp[i][j] != -1){
            return dp[i][j];
        }

        // Recursive Case : 
        // Case 1 : Alice picks the first stone at index i (Left pile for Bob : i + 1... j)
        int ans1 = piles[i] + min(takeStone(piles, i + 2, j, dp), takeStone(piles, i + 1, j - 1, dp));

        // Case 2 : Alice picks the last stone at index j (Left pile for Bob : i...j - 1)
        int ans2 = piles[j] + min(takeStone(piles, i + 1, j - 1, dp), takeStone(piles, i, j - 2, dp));
        return dp[i][j] = max(ans1, ans2);
    }

public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        int stones = 0;
        for (int s : piles)     stones += s;

        vector<vector<int>> dp(n, vector<int>(n, -1));
        int alice = takeStone(piles, 0, n - 1, dp);
        if (alice > stones - alice){
            return true;
        }

        return false;
    }
};