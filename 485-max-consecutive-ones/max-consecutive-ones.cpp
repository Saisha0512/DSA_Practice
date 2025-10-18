class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int i = 0, len = 0;
        for (int j = 0; j < n; j ++){
            if (nums[j] == 0){
                if (j + 1 < n){
                    i = j + 1;
                }
            }
            else {
                len = max(len, j - i + 1);
            }
        }
        return len;
    }
};