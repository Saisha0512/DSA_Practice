class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> odd(n, 0);
        for (int i = 0; i < n; i ++){
            odd[i] = ((nums[i] % 2 != 0)? 1 : 0) + ((i > 0)? odd[i - 1] : 0);
        }

        unordered_map<int, int> m; // {No of odd nos till the current index, Frequency}
        m[0] = 1;
        int cnt = 0;
        for (int i = 0; i < n; i ++){
            if (m.find(odd[i] - k) != m.end()){
                cnt += m[odd[i] - k];
            }

            m[odd[i]] ++;
        }

        return cnt;
    }
};