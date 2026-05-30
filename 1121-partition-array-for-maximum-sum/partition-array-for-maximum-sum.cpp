// TOP - DOWN APPROACH : 
class Solution {
    vector<int> dp;
    // dp[i] = largst sum of given array using the first i numbers of the given array

    int sum(vector<int> &arr, int k, int n){
        // base case 
        if (n == 0){
            return 0;
        }
        if (n == 1){
            return arr[n - 1];
        }

        // check dp
        if (dp[n] != -1){
            return dp[n];
        }

        // recursive case
        // iterating over all the possible values of k - ie. iterating over all the possible elements in the nearby of the current element, whose values can be changed to the current element
        // ie. we consider that one of the partition ends at the current index
        int tempans = INT_MIN;
        for (int i = 1; i <= min(n, k); i ++){
            int currans = sum(arr, k, n - i);

            int maxel = *max_element(arr.begin() + n - i, arr.begin() + n);
            currans += (i * maxel);

            tempans = max(tempans, currans);
        }

        return dp[n] = tempans;
    }

public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        dp.resize(n + 1, -1);
        
        return sum(arr, k, n);
    }
};