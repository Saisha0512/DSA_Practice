class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long ressum = 1e18;
        for (int i = 0; i < n - 2; i ++){
            int j = i + 1, k = n - 1;

            while (j < k){
                long long currsum = nums[i] + nums[j] + nums[k];

                // Checking the absolute difference : 
                if (abs(ressum - target) > abs(currsum - target)){
                    ressum = currsum;
                }

                if (target > currsum){
                    j ++;
                }
                else {
                    k --;
                }
            }
        }

        return (int)ressum;
    }
};