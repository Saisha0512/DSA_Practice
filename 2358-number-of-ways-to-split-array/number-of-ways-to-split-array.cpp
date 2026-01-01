class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();

        vector<long long> left(n, 0), right(n, 0);
        for (int i = 0; i < n; i ++){
            // Left prefix : 
            left[i] = nums[i] + ((i > 0)? left[i - 1] : 0);

            // Right prefix :
            right[n - 1 - i] = nums[n - 1 - i] + ((i > 0)? right[n - i] : 0);
        }

        int cnt = 0;
        for (int i = 0; i < n - 1; i ++){
            if (left[i] >= right[i + 1]){
                cnt ++;
            }
        }

        return cnt;
    }
};