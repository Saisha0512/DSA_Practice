class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i ++){
            if (nums[i] == 0){
                nums[i] = -1;
            }
        }

        unordered_map<int, int> mp;
        mp[0] = -1;
        int presum = 0, max_len = 0;
        for (int i = 0; i < n; i ++){
            presum += nums[i];

            if (mp.find(presum) != mp.end()){
                max_len = max(max_len, i - mp[presum]);
            }
            else {
                mp[presum] = i;
            }
        }

        return max_len;
    }
};