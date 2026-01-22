class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int cnt = 0;

        while (true){
            bool flag = true;

            // Check if the array is non - decreasing : 
            for (int i = 1; i < nums.size(); i ++){
                if (nums[i] < nums[i - 1]){
                    flag = false;
                    break;
                }
            }

            // Already sorted in non - decreasing order : 
            if (flag){
                break;
            }

            int i = 0;
            int minSum = INT_MAX, idx = 0;

            // Find minimum adjacent pair : 
            while (i + 1 < nums.size()){
                if (nums[i] + nums[i + 1] < minSum){
                    minSum = nums[i] + nums[i + 1];
                    idx = i;
                }

                i ++;
            }

            // Merge : 
            nums[idx] += nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);
            cnt ++;
        }

        return cnt;
    }
};