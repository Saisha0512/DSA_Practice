class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(n<=1)return 0;
        int ans = INT_MIN;
        for(int i = 0 ; i < n-1 ; i++){
            if(nums[i+1]-nums[i] > ans){
                ans = nums[i+1]-nums[i];
            }
        }
        return ans;
    }
};