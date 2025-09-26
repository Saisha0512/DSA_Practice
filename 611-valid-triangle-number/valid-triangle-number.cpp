class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int cnt = 0;
        for (int i = nums.size() - 1; i >= 2; i --){
            int j = 0, k = i - 1;
            while (j < k){
                if (nums[j] + nums[k] > nums[i]){
                    cnt += (k - j);
                    k --;
                }
                else {
                    j ++;
                }
            }
        }
        return cnt;
    }
};