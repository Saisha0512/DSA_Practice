class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int cnt = 0, last = INT_MIN;

        for (int num : nums){
            int temp = max(num - k, last + 1);
            if (temp <= num + k){
                cnt ++;
                last = temp;
            }
        }
        return cnt;
    }
};