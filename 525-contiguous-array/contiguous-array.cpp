class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i ++){
            if (nums[i] == 0){
                nums[i] = -1;
            }
        }

        vector<int> pre(n, 0);
        pre[0] = nums[0];
        for (int i = 1; i < n; i ++){
            pre[i] = pre[i - 1] + nums[i];
        }

        // Checking sum at every point : 
        int maxlen = 0;
        unordered_map<int, int> m;
        m[0] = -1;
        for (int i = 0; i < n; i ++){
            if (pre[i] == 0){
                maxlen = max(maxlen, i + 1);
            }
            else {
                if (m.find(pre[i]) != m.end()){
                    maxlen = max(maxlen, i - m[pre[i]]);
                }
                else {
                    m[pre[i]] = i;
                }
            }
        }

        return maxlen;
    }
};