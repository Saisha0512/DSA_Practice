class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;

        for (int num : nums){
            // If the current element already appears in the set : 
            if (s.find(num) != s.end()){
                return true;
            }
            else {
                s.insert(num);
            }
        }

        return false;
    }
};