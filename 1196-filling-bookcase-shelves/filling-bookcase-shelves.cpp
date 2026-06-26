class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int width) {
        int n = books.size();

        // dp intialization
        vector<int> dp(n, 0);
        dp[0] = books[0][1];
        // dp[i] = min possible height of the total bookshelf, if we consider the books till the ith index

        // bottom up loop
        for (int i = 1; i < n; i ++){
            int min_ans = INT_MAX;
            int rem_width = width;
            int curr_max_ht = INT_MIN;
            for (int j = i; j >= 0; j --){
                // placing this book as well on the current shelf
                if (books[j][0] <= rem_width){
                    curr_max_ht = max(curr_max_ht, books[j][1]);
                    int curr_ans = curr_max_ht + ((j > 0)? dp[j - 1] : 0);

                    min_ans = min(min_ans, curr_ans);
                    rem_width -= books[j][0];
                }
                // otherwise, stop placing
                else {
                    break;
                }
            }

            dp[i] = min_ans;
        }

        return dp[n - 1];
    }
};