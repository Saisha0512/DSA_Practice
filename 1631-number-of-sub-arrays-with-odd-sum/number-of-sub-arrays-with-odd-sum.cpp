class Solution {
    const int mod = 1e9 + 7;

public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();

        vector<int> pre(n, 0);
        pre[0] = arr[0];
        for (int i = 1; i < n; i ++){
            pre[i] = pre[i - 1] + arr[i];
        }

        // accumulating the no of even prefix sums
        vector<int> even(n), odd(n);
        even[0] = 1; // empty prefix
        if (pre[0] % 2 == 0){
            even[0] ++;
        }
        else {
            odd[0] = 1;
        }

        for (int i = 1; i < n; i ++){
            if (pre[i] % 2 == 0){
                even[i] = (even[i - 1] + 1) % mod;
                odd[i] = odd[i - 1];
            }
            else {
                odd[i] = (odd[i - 1] + 1) % mod;
                even[i] = even[i - 1];
            }
        }

        // for every odd prefix sum encountered, we need to check how many previous even sums are there
        // ODD - EVEN = ODD
        // EVEN - ODD = ODD
        int cnt = 0;
        for (int i = 0; i < n; i ++){
            // current sum is odd
            if (pre[i] % 2 == 1){
                cnt = (cnt + even[i]) % mod;
            }
            // current sum is even
            else {
                cnt = (cnt + odd[i]) % mod;
            }
        }

        return cnt;
    }
};