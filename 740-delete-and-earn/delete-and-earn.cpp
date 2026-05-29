// TOP - DOWN APPROACH : 
class Solution {
    vector<int> dp;
    // dp[i] = max no of points on using numbers from 0...n in the given array

    int del(vector<int> &points, int n){
        // base case
        if (n == 0){ // no points would be there correspondig to 0
            return 0;
        }
        // if (freq[n - 1] == 0){
        //     return 0;
        // }
        if (n == 1){ // only one element is left, then max case would be to take it
            return points[n];
        }

        // check dp
        if (dp[n] != -1){
            return dp[n];
        }

        // recursive case
        // case 1 : to not delete the current element - we just skip
        int op1 = del(points, n - 1);

        // case 2 : to delete the current element and skip the next case 
        // if we are deleting the current element, then we count the points
        // contributed by all of its occurrences
        int op2 = points[n] + del(points, n - 2);

        return dp[n] = max(op1, op2);        
    }

public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();

        // finding the max element
        int maxel = *max_element(nums.begin(), nums.end());

        // counting the total points corresponding to each element
        vector<int> points(maxel + 1, 0);
        for (int num : nums){
            points[num] += num;
        }

        // dp intialization
        dp.resize(maxel + 1, -1);

        return del(points, maxel);
    }
};