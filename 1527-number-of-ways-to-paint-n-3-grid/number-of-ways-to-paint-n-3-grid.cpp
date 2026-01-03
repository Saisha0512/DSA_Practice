class Solution {
public:
    int numOfWays(int n) {
        int mod = 1e9 + 7;
        // No of ways to paint the first row : 
        long long aba = 6, abc = 6;

        for (int i = 1; i < n; i ++){
            // No of ways to paint the current row depends on the number of ways to paint the previous row in the following way : 
            // 1. Every ABA Pattern generates : 3 ABA + 2 ABC
            long long newaba = (3*aba + 2*abc) % mod;

            // 2. Every ABC Pattern generates : 2 ABA + 2 ABC
            long long newabc = (2*aba + 2*abc) % mod;

            // Updating the number of possible ways in the last row, for the next row in the next iteration
            aba = newaba;
            abc = newabc;
        }

        // Returning the answer for the last row : 
        return (aba + abc) % mod;
    }
};