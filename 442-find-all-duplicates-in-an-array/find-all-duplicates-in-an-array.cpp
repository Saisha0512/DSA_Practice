class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();

        // counting the frequency of each element
        vector<int> freq(n + 1, 0);
        for (int num : nums){
            freq[num] ++;
        }

        // checking for the elements that appear twice
        vector<int> res;
        for (int i = 0; i <= n; i ++){
            if (freq[i] == 2){
                res.push_back(i);
            }
        }

        return res;
    }
};