class Solution {
public:
    int numTrees(int n) {
        // dp initialization
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1; // null tree or single root tree

        // bottom - up loop
        for (int i = 1; i <= n; i ++){
            // for i nodes, we will try to make each nodes from 1...i as the root in ever sub-case

            int tempans = 0;
            for (int k = 1; k <= i; k ++){
                // left subtree will be formed using k - 1 nodes
                int ltree = dp[k - 1];
                // right subtree will be formed using n - k nodes
                int rtree = dp[i - k];

                // each left subtree can be mapped to each possible right subtree
                tempans += (ltree * rtree);
            }

            dp[i] = tempans;
        }

        return dp[n];
    }
};