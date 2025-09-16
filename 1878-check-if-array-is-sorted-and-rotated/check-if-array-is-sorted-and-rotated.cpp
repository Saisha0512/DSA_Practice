class Solution {
public:
    bool check(vector<int>& nums) {
        int breaks = 0;
        for (int i = 0; i < nums.size(); i ++){
            if (nums[i] > nums[(i + 1) % nums.size()]){
                breaks ++;
            }
            if (breaks > 1){
                return false;
            }
        }
        return true;
    }
};