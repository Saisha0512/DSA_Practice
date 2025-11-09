class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int pos = 0, neg = 1;

        for (int n : nums){
            // Updating positive elements at the even index : 
            if (n > 0){
                res[pos] = n;
                pos += 2;
            }
            // Updating negative elements at the odd index : 
            else {
                res[neg] = n;
                neg += 2;
            }
        }

        return res;
    }
};