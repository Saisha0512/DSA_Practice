class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int cnt = 0;
        
        while (true){
            bool flag = true;

            // Checking if the array is in non - decreasing order : 
            for (int i = 1; i < nums.size(); i ++){
                if (nums[i] < nums[i - 1]){
                    flag = false;
                    break;
                }
            }

            // If the array is in non - decreasing order : 
            if (flag){
                break;
            }

            // Finding the pair with the minimum sum : 
            int idx = 0;
            int minSum = INT_MAX;
            for (int i = 0; i < nums.size() - 1; i ++){
                if (nums[i] + nums[i + 1] < minSum){
                    idx = i;
                    minSum = nums[i] + nums[i + 1];
                }
            }

            // Replacing with the minSum : 
            nums[idx] += nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);
            cnt ++;
        }

        return cnt;
    }
};