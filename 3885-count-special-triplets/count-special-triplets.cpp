class Solution {
public:
    long long MOD = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        // Unirdered map to store the frequencies of the numbers appearing to the left & right of the current number : 
        unordered_map<long long, long long> left, right;

        // Initally storing the frequencies in the right freq map : 
        for (long long num : nums){
            right[num] ++;
        }

        // Iterating over each element & checking the frequencies of its left & right elements : 
        long long cnt = 0;

        for (long long num : nums){
            // Removing the current element from the right side counts : 
            right[num] --;

            long long target = 2*num;
            // Checking the left & right side counts of the target : 
            long long lcnt = left[target], rcnt = right[target];

            // As all the left side targets can make a triplet with the current element & all the right side target, the answer will be : 
            cnt = (cnt + (lcnt * rcnt) % MOD) % MOD;

            // Putting the current element in the left side counts for the elements ahead : 
            left[num] ++;
        }

        return cnt;
    }
};