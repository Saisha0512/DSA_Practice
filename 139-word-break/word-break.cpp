class Solution {
    unordered_set<string> words;
    unordered_map<string, bool> dp;
    
    bool check(string s){
        // base case
        if (words.count(s) || words.empty()){
            return true;
        }

        // check dp
        if (dp.count(s)){
            return dp[s];
        }

        // recursive case
        int n = s.size();
        for (int k = 1; k < n; k ++){
            bool op1 = check(s.substr(0, k));
            bool op2 = check(s.substr(k, n - k));

            if (op1 && op2){
                return dp[s] = true;
            }
        }

        return dp[s] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        words = unordered_set<string>(wordDict.begin(), wordDict.end());

        return check(s);
    }
};