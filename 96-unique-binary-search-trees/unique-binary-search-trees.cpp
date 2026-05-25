// TOP - DOWN APPROACH : 
class Solution {
    vector<int> dp;
    // dp[i] = no of structurally unique bst which can be formed using i nodes

    int tree(int n){
        // base case
        if (n == 0 || n == 1){
            return 1;
        }

        // check dp
        if (dp[n] != -1){
            return dp[n];
        }

        // recursive case
        int tempans = 0;
        // we would consider one of these n nodes as root one at a time
        for (int k = 1; k <= n; k ++){
            // the left subtree will be formed using (k - 1) nodes
            int ltree = tree(k - 1);
            // the right subtree will be formed using (n - k) nodes
            int rtree = tree(n - k);

            // on counting the combinations each left subtree can be mapped with each of the right subtrees
            tempans = tempans + (ltree * rtree);
        }

        return dp[n] = tempans;
    }

public:
    int numTrees(int n) {
        dp.resize(n + 1, -1);

        return tree(n);
    }
};