class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();

        int mindiff = INT_MAX;
        for (int i = 0; i < n; i ++){
            if (nums[i] == target){
                mindiff = min(mindiff, abs(i - start));
            }
        }

        return mindiff;
    }
};