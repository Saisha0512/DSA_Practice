// TOP - DOWN APPROACH : NOT POSSIBLE
// BOTTOM - UP APPROACH : 
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int, int> dp;
        // dp[i] = length of maximum subseq ending at the element i in the given array

        int ans = INT_MIN;
        for (auto &val : arr){
            // case 1 : if the element = val - diff is not present in the array before the current element
            if (dp.find(val - diff) == dp.end()){
                dp[val] = 1;
            }
            // case 2 : if the element = val - diff, is present in the array, before the current element, then we extend the subseq
            else {
                dp[val] = dp[val - diff] + 1;
            }

            // taking the maximum length overall the possible cases
            ans = max(ans, dp[val]);
        }

        return ans;
    }
};