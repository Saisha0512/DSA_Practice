// TOP - DOWN APPROACH : 
class Solution {
    vector<vector<int>> dp;
    // dp[i][j] = can the frog reach the last stone if it starts from the stone at ith index, with the last jump length = j
    unordered_map<int, int> pos;
    // {stones[i], i}

    int jump(vector<int> &stones, int i, int last){
        // base case
        if (last == 0 || i >= stones.size()){
            return false;
        }
        if (i == stones.size() - 1){
            return true;
        }

        // check dp
        if (dp[i][last] != -1){
            return dp[i][last];
        }

        // recursive case
        // case 1 : jumping last - 1 units forward
        int op1 = false;
        if (pos.find(stones[i] + last - 1) != pos.end()){
            op1 = jump(stones, pos[stones[i] + last - 1], last - 1);
        }

        // case 2 : jumping last units forward
        int op2 = false;
        if (pos.find(stones[i] + last) != pos.end()){
            op2 = jump(stones, pos[stones[i] + last], last);
        }

        // case 3 : jumping last + 1 units forward
        int op3 = false;
        if (pos.find(stones[i] + last + 1) != pos.end()){
            op3 = jump(stones, pos[stones[i] + last + 1], last + 1);
        }

        return dp[i][last] = (op1 || op2 || op3);
    }

public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        // base case
        if (stones[1] != 1){
            return false;
        }

        // dp intializaation 
        dp.resize(n, vector<int>(n, -1));
        // n x n = (no of indices x maximum jump length that could be there at the last jump)

        // storing the indices of stones corresponding to their ositions in the river
        for (int i = 0; i < n; i ++){
            pos[stones[i]] = i;
        }

        return jump(stones, 1, 1);
    }
};