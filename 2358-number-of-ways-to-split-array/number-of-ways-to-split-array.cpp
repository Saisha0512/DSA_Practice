class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
        for (int num : nums)    total += num;

        int cnt = 0;
        long long pre = 0;
        for (int i = 0; i < n - 1; i ++){
            pre += nums[i];
            if (pre >= total - pre){
                cnt ++;
            }
        }

        return cnt;
    }
};