class Solution {
    int takeEl(vector<int> &a, vector<int> &b, int i, int j, vector<vector<int>> &dp){
        // Base Case : 
        if (i < 0 || j < 0){
            return INT_MIN;
        }

        // Check DP : 
        if (dp[i][j] != -1){
            return dp[i][j];
        }

        // Recursive Case : 
        // Case 1 : Taking both elements at index i & j 
        int ans1 = a[i]*b[j] + max(0, takeEl(a, b, i - 1, j - 1, dp));

        // Case 2 : Not taking any of the elements at index i & j
        int ans2 = takeEl(a, b, i - 1, j - 1, dp);

        // Case 3 : Only taking the element at index i
        int ans3 = takeEl(a, b, i, j - 1, dp);

        // Case 4 : Only taking the element at index j
        int ans4 = takeEl(a, b, i - 1, j, dp);

        return dp[i][j] = max(ans1, max(ans2, max(ans3, ans4)));
    }

public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return takeEl(a, b, n - 1, m - 1, dp);
    }
};