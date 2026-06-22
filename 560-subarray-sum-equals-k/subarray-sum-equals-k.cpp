class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        int presum = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i ++){
            presum += nums[i];

            // overall sum ending at the current index == k
            if (presum == k){
                cnt ++;
            }
            // some subarray ending at the current index == k
            if (m.find(presum - k) != m.end()){
                cnt += m[presum - k];
            }
            m[presum] ++;
        }

        return cnt;
    }
};