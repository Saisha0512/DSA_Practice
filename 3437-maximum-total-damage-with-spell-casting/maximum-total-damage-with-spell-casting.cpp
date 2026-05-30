// BOTTOM - UP APPROACH : 
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        // calculating the total damage caused by each unique spell
        unordered_map<long long, long long> damage;
        for (int num : power){
            damage[num] += num;
        }
        // storing the values of unique spells in sorted order
        vector<long long> val;
        for (auto &p : damage){
            val.push_back(p.first);
        }
        sort(val.begin(), val.end());

        // dp initialization
        int n = val.size();
        vector<long long> dp(n, -1);

        // bottom up loop
        for (int i = 0; i < n; i ++){
            // case 1 : skip casting the current spell
            long long op1 = (i - 1 >= 0)? dp[i - 1] : 0;

            // case 2 : cast the current spell & skip the 2 adjacent spells
            long long currpow = val[i];
            long long op2 = damage[currpow];

            long long j = lower_bound(val.begin(), val.end(), currpow - 2) - val.begin() - 1;
            op2 += (j >= 0)? dp[j] : 0;

            dp[i] = max(op1, op2);
        }

        return dp[n - 1];
    }
};