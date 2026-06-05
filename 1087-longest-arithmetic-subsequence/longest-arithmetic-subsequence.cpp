// BOTTOM - UP APPROACH : 
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        // base case 
        if (n <= 2){
            return n;
        }

        // dp intialization
        int ans = 2;
        vector<unordered_map<int, int>> dp(n);
        // dp[i][diff] = length of longest arithmetic subseq ending at the ith index with a difference between the elements = diff

        // bottom up loop
        for (int i = 0; i < n; i ++){
            // iterating over all the previous elements
            for (int j = 0; j < i; j ++){
                int diff = nums[i] - nums[j];
                // if there exists a subseq that ends t the jth index with the difference between its elements = diff
                // then we extend that subseq
                if (dp[j].find(diff) != dp[j].end()){
                    dp[i][diff] = dp[j][diff] + 1;
                }
                // otherwise we don't extend the subseq
                else {
                    dp[i][diff] = 2;
                }

                ans = max(ans, dp[i][diff]);
            }
        }

        return ans;
    }
};