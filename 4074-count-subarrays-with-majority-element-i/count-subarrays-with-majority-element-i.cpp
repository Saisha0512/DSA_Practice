class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        // as in terms of prefix sum 
        // for target +1, for other elements -1
        // we need to find & count those subarrays whose sum > 0
        // prefix[l] - prefix[r - 1] > 0, for all r < l && r > 0
        // prefix[l] > prefix[r - 1]

        // for any array the prefix sum lies in the range [-n, n]
        // so we make the range [0, 2n]
        // and along the way we count the appearances or frequency of these prefix sum we had encountered
        // and at any point we add the sum of those frequencies of those prefix sums who are less than the current prefix sum

        vector<int> freq(2*n + 1, 0);
        freq[0 + n] = 1;
        
        int curr = n; // since we start with prefix sum = 0
        int presum = 0; // stores the prefix of frequencies along the way
        int cnt = 0; // total count of valid subarrays

        for (int i = 0; i < n; i ++){
            // updating the current prefix sum
            // target element found
            if (nums[i] == target){ 
                // since we are moving curr -> curr + 1, so for curr + 1, prefix value of curr, would be valid as curr < curr + 1
                curr ++;
                presum += freq[curr - 1];
                freq[curr] ++;
            }
            else {
                // since now we are moving curr -> curr - 1, so when it was curr, then curr - 1 was valid, but now as it is curr - 1, then curr - 1 would not be a vlid prefix as curr - 1 <(not) curr - 1
                curr --;
                presum -= freq[curr];
                freq[curr] ++;
            }

            cnt += presum; // adding the number of prefix sums that had appeared earlier which are smaller than the curr prefix sum
        }

        return cnt;
    }
};