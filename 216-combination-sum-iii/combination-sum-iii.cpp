class Solution {
    void checkComb(int start, int k, int target, vector<int> &curr, vector<vector<int>> &res){
        // Base Case : 
        if (curr.size() == k && target == 0){
            res.push_back(curr);
            return;
        }

        if (curr.size() >= k || target <= 0){
            return;
        }

        // Recursive Case : 
        for (int i = start; i <= 9; i ++){
            if (i > target){
                break;
            }

            curr.push_back(i);
            checkComb(i + 1, k, target - i, curr, res);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        vector<vector<int>> res;
        checkComb(1, k, n, curr, res);

        return res;
    }
};