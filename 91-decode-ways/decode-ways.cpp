// TOP - DOWN APPROACH : 
class Solution {
    int decode(string &s, int n, vector<int> &dp){
        // base case
        if (n == 0){
            return 1; // empty string
        }
        if (n == 1){
            if (s[n - 1] != '0'){
                return 1;
            }
            return 0;
        }

        // check dp
        if (dp[n] != -1){
            return dp[n];
        }

        // recursive case
        dp[n] = 0;
        // single digit
        if (n - 1 >= 0 && s[n - 1] != '0'){
            dp[n] += decode(s, n - 1, dp);
        }
        // double digit
        int num = stoi(s.substr(n - 2, 2));
        if (num >= 10 && num <= 26){
            dp[n] += decode(s, n - 2, dp);
        }

        return dp[n];
    }

public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        return decode(s, n, dp);
    }
};