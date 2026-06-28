class Solution {
    int atMostK(vector<int> &nums, int k){
        int n = nums.size();
        int cnt = 0;
        int l = 0, dist = 0;
        vector<int> freq(n + 1, 0);
        for (int r = 0; r < n; r ++){
            // expanding the window
            freq[nums[r]] ++;
            if (freq[nums[r]] == 1){
                dist ++;
            }

            // contracting the window
            while (dist > k){
                freq[nums[l]] --;
                if (freq[nums[l]] == 0){
                    dist --;
                }
                l ++;
            }

            // adding the number of all the possible subarrays in this window
            cnt += (r - l + 1);
        }

        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};