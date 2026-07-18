class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        freq[0] = 1;

        int cnt = 0;
        int preodd = 0;
        for (int i = 0; i < n; i ++){
            if (nums[i] % 2 == 1){
                preodd ++;
            }

            if (freq.count(preodd - k)){
                cnt += freq[preodd - k];
            }

            freq[preodd] ++;
        }

        return cnt;
    }
};