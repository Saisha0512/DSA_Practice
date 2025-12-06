class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> res(n, -1);

        for (int i = 0; i < n; i ++){
            for (int step = 1; step < n; step ++){
                int idx = (i + step) % n;
                if (nums[idx] > nums[i]){
                    res[i] = nums[idx];
                    break;
                }
            }
        }

        return res;
    }
};