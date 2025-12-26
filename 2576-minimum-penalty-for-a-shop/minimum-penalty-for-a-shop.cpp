class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        vector<int> righty(n + 1, 0), leftn(n + 1, 0);
        
        // Calculating left prefix sums : 
        for (int i = 1; i <= n; i ++){
            if (customers[i - 1] == 'N'){
                leftn[i] = leftn[i - 1] + 1;
            }
            else {
                leftn[i] = leftn[i - 1];
            }
        }

        // Calculating right prefix sum : 
        for (int i = n - 1; i >= 0; i --){
            if (customers[i] == 'Y'){
                righty[i] = righty[i + 1] + 1;
            }
            else {
                righty[i] = righty[i + 1];
            }
        }

        // Checking for the minimum penalty : 
        int minidx = 0, penalty = INT_MAX;
        for (int i = 0; i <= n; i ++){
            int curr = leftn[i] + righty[i];
            if (curr < penalty){
                penalty = curr;
                minidx = i;
            }
        }

        return minidx;
    }
};