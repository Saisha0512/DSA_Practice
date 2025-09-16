class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res;
        for (int num : nums){
            int curr = num;
            while (!res.empty() && gcd(res.back(), curr) > 1){
                curr = lcm(curr, res.back());
                res.pop_back();
            }
            res.push_back(curr);
        }
        return res;
    }
};