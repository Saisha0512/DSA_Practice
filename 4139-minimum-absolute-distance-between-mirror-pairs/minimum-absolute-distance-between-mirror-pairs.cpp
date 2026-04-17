class Solution {
    int revNo(int num){
        int rev = 0;

        while (num > 0){
            rev = rev * 10 + (num % 10);
            num /= 10;
        }

        return rev;
    }

public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        int ans = INT_MAX;

        for (int i = 0; i < n; i ++){
            if (m.find(nums[i]) != m.end()){
                ans = min(ans, i - m[nums[i]]);
            }

            m[revNo(nums[i])] = i;
        }

        return (ans == INT_MAX)? -1 : ans;
    }
};