class Solution {
public:
    int finalElement(vector<int>& nums) {
        int n = nums.size();
        // Base Case : 
        if (n == 1){
            return nums[0];
        }
        
        // Calculating prefix & suffix minimum array : 
        vector<int> pre(n), suf(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; i ++){
            pre[i] = min(pre[i - 1], nums[i]);
        }

        suf[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i --){
            suf[i] = min(suf[i + 1], nums[i]);
        }

        // Alice removing : 
        int ans = INT_MIN;
        // Removing prefix : 
        for (int i = 0; i < n - 1; i ++){
            ans = max(ans, suf[i + 1]);
        }

        // Removing suffix : 
        for (int i = 1; i < n; i ++){
            ans = max(ans, pre[i - 1]);
        }

        // Removing middle part : 
        for (int i = 1; i < n - 1; i ++){
            ans = max(ans, min(pre[i - 1], suf[i + 1]));
        }

        return ans;
    }
};