class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int cnt = 0;
        int preodd = 0;
        unordered_map<int, int> m;
        for (int num : nums){
            preodd += (num % 2)? 1 : 0;

            if (preodd == k){
                cnt ++;
            }

            if (m.find(preodd - k) != m.end()){
                cnt += m[preodd - k];
            }
            m[preodd] ++;
        }

        return cnt;
    }
};