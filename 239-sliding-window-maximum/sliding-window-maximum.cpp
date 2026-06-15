class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < n; i ++){
            // popping the elements that are out of the window
            while (!dq.empty() && dq.front() <= i - k){
                dq.pop_front();
            }

            // popping the elements that are smaller
            while (!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }

            // pushing the current element
            dq.push_back(i);

            // only adding to the result - if the window is valid
            if (i >= k - 1){
                res.push_back(nums[dq.front()]);
            }
        }

        return res;
    }
};