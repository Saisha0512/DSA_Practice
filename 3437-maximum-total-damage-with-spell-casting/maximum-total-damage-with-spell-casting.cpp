// TOP - DOWN APPROACH : 
class Solution {
    vector<long long> dp;
    // dp[i] = max possible total damage caused while considering the spells till the ith index in val array

    long long cast(vector<long long> &val, unordered_map<long long, long long> &damage, int n){
        // base case
        if (n < 0){
            return 0;
        }

        // check dp
        if (dp[n] != -1){
            return dp[n];
        }

        // recursive case
        // case 1 : skip casting the current spell
        long long op1 = cast(val, damage, n - 1);

        // case 2 : cast the current spell & skip n - 1 & n - 2, jump straight to n - 3
        long long currpow = val[n];
        long long op2 = damage[currpow];
        long long i = lower_bound(val.begin(), val.end(), currpow - 2) - val.begin() - 1;
        op2 += cast(val, damage, i);

        return dp[n] = max(op1, op2);
    }

public:
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();

        // calculating the damage caused by all the occurrences of each damage
        int maxel = *max_element(power.begin(), power.end());
        unordered_map<long long, long long> damage;
        for (int num : power){
            damage[num] += num;
        }
        // storing the unique power values of spells in increasing order
        vector<long long> val;
        for(auto &p : damage){
            val.push_back(p.first);
        }
        sort(val.begin(), val.end());

        // dp initialization
        dp.resize(val.size(), -1LL);

        return cast(val, damage, val.size() - 1);
    }
};