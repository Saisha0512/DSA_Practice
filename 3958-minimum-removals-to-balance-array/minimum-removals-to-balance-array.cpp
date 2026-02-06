class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int maxlen = 0;
        int l = 0;
        // Expanding the window : 
        for (int r = 0; r < n; r ++){
            // Contracting the window : 
            while ((long long)nums[r] > (long long)nums[l] * k){
                l ++;
            }

            // Finding the maximum length of the window possible : 
            maxlen = max(maxlen, r - l + 1);
        }

        // Deleting all the other elements : 
        return (n - maxlen);
    }
};