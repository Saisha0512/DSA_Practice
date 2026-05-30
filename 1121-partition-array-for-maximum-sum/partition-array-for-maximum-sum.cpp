// BOTTOM - UP APPROACH : 
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        // calculating the prefix maximum
        vector<int> premax(n);
        premax[0] = arr[0];
        for (int i = 1; i < n; i ++){
            premax[i] = max(premax[i - 1], arr[i]);
        }

        // dp initialization
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        dp[1] = arr[0];

        // bottom up loop
        for (int i = 2; i <= n; i ++){
            int tempans = INT_MIN;

            // considering all possible windows of size atmost k, ending at the current index
            for (int j = 1; j <= k && i - j >= 0; j ++){
                int currans = dp[i - j];

                // changing all the elements in this window to the max element in that window
                int maxel = *max_element(arr.begin() + i - j, arr.begin() + i);
                currans += (j * maxel);

                tempans = max(tempans, currans);
            }

            dp[i] = tempans;
        }

        return dp[n];
    }
};