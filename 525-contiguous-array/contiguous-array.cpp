class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        // Checking sum at every point : 
        int maxlen = 0, pre = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i ++){
            // Adding -1 for 0 & 1 for 1 : 
            if (nums[i] == 0){
                pre --;
            }
            else {
                pre ++;
            }

            // Checking for the last occurrence : 
            if (pre == 0){
                maxlen = max(maxlen, i + 1);
            }
            else {
                if (m.find(pre) != m.end()){
                    maxlen = max(maxlen, i - m[pre]);
                }
                else {
                    m[pre] = i;
                }
            }
        }

        return maxlen;
    }
};