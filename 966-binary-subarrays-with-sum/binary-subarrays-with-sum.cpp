class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int pre = 0, cnt = 0;
        unordered_map<int, int> freq;
        freq[0] = 1;
        for (int i = 0; i < nums.size(); i ++){
            pre += nums[i];
            if (freq.find(pre - goal) != freq.end()){
                cnt += freq[pre - goal];
            }
            freq[pre] ++;
        }
        return cnt;
    }
};