// TOP - DOWN APPROACH : 
class Solution {
    vector<vector<int>> dp;
    unordered_map<int, int> pos;

    int jump(vector<int> &stones, int i, int last){
        // base case
        if (last <= 0 || last > stones.size()){
            return 0;
        }
        if (i == stones.size() - 1){
            return 1;
        }

        // check dp
        if (dp[i][last] != -1){
            return dp[i][last];
        }

        // recursive case
        int op1 = false, op2 = false, op3 = false;
        // case 1 : jumping last - 1 units forward
        if (pos.find(stones[i] + last - 1) != pos.end()){
            op1 = jump(stones, pos[stones[i] + last - 1], last - 1);
        }
        // case 2 : jumping last units forward
        if (pos.find(stones[i] + last) != pos.end()){
            op2 = jump(stones, pos[stones[i] + last], last);
        }
        // case 3 : jumping last + 1 units forward
        if (pos.find(stones[i] + last + 1) != pos.end()){
            op3 = jump(stones, pos[stones[i] + last + 1], last + 1);
        }

        return dp[i][last] = (op1 || op2 || op3);
    }

public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        // not possible to start jumping
        if (stones[1] != 1){
            return false;
        }

        // int maxdiff = stones[n - 1] - stones[0];

        // dp intialization
        dp.resize(n, vector<int>(n + 1, -1));
        // storing the index positions of each stone
        for (int i = 0; i < n; i ++){
            pos[stones[i]] = i;
        }

        return jump(stones, 1, 1);
    }
};