// TOP - DOWN APPROACH : 
class Solution {
    vector<int> dp;

    int ways(string s, int i){
        // base case
        if (i < 0){ // successfully decoded the entire string
            return 1; // we return 1 to mark one valid decoding way
        }

        // check dp
        if (dp[i] != -1){
            return dp[i];
        }

        // recursive case
        // case 1 : evaluating the current character as a single digit num
        int op1 = 0;
        if (s[i] != '0'){
            op1 = ways(s, i - 1);
        }

        // case 2 : evaluating the current character as a 2 - digit num
        int op2 = 0;
        if (i - 1 >= 0){
            int idx = stoi(s.substr(i - 1, 2));
            if (idx >= 10 && idx <= 26){
                op2 = ways(s, i - 2);
            }
        }

        return dp[i] = op1 + op2;
    }

public:
    int numDecodings(string s) {
        int n = s.size();
        dp.resize(n, -1);

        return ways(s, n - 1);
    }
};