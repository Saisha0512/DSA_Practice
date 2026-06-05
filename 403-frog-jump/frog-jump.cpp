// BOTTOM - UP APPROACH : 
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        // base case
        if (stones[1] != 1){
            return false;
        }

        // dp intialization
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        // dp[i][j] = can the frog reach the last stone, if it starts from the ith index, with the last jump length = j
        unordered_map<int, int> pos; // to map the river positions of stones to their corresponding indices of the array
        for (int i = 0; i < n; i ++){
            pos[stones[i]] = i;
        }

        // base case intialization
        // if i == n - 1 -> true
        for (int j = 0; j < n; j ++){
            dp[n - 1][j] = true;
        }
        // if last jump length == 0, no jump possible
        for (int i = 0; i < n; i ++){
            dp[i][0] = false;
        }

        // bottom up loop
        for (int i = n - 2; i >= 0; i --){
            for (int j = 1; j < n; j ++){
                // case 1 : jumping j - 1 units forward
                bool op1 = false;
                if (j > 1 && pos.find(stones[i] + j - 1) != pos.end()){
                    op1 = dp[pos[stones[i] + j - 1]][j - 1];
                }

                // case 2 : jumping j units forward
                bool op2 = false;
                if (pos.find(stones[i] + j) != pos.end()){
                    op2 = dp[pos[stones[i] + j]][j];
                }

                // case 3 : jumping j + 1 units forward
                bool op3 = false;
                if (j + 1 < n && pos.find(stones[i] + j + 1) != pos.end()){
                    op3 = dp[pos[stones[i] + j + 1]][j + 1];
                }

                dp[i][j] = (op1 || op2 || op3);
            }
        }

        return dp[1][1];
    }
};