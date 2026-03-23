class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> m;
        int prefix = 0, cnt = 0;
        m[0] = 1;
        for (int i = 0; i < nums.size(); i ++){
            prefix += nums[i];

            if (m.find(prefix - k) != m.end()){
                cnt += m[prefix - k];
            }
            m[prefix] ++;
        }
        return cnt;
    }
};