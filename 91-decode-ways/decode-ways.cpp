class Solution {
    vector<int> dp;
    // dp[i] = no of ways to decode string s of length i

    int decode(string s, int n){
        // base case
        if (n == 0){
            return 1;
        }

        // check dp
        if (dp[n] != -1){
            return dp[n];
        }

        // recursive case
        // case 1 : using only the (n - 1)th character to decode as a single digit
        int op1 = 0;
        if (n - 1 >= 0 && s[n - 1] != '0'){
            op1 = decode(s, n - 1);
        }

        // case 2 : using last 2 characters of the string to decode only if valid
        int op2 = 0;       
        if (n - 2 >= 0 && s[n - 2] != '0'){
            int num = stoi(s.substr(n - 2, 2));
            if (num >= 10 && num <= 26){
                op2 = decode(s, n - 2);
            }
        }

        return dp[n] = op1 + op2;
    }

public:
    int numDecodings(string s) {
        int n = s.size();
        dp.resize(n + 1, -1);

        return decode(s, n);
    }
};