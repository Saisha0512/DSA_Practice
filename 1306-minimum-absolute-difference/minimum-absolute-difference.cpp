class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        vector<vector<int>> res;

        for (int i = 1; i < n; i ++){
            if (minDiff > arr[i] - arr[i - 1]){
                minDiff = arr[i] - arr[i - 1];
                res = {};
                res.push_back({arr[i - 1], arr[i]});
            }
            else if (minDiff == arr[i] - arr[i - 1]){
                res.push_back({arr[i - 1], arr[i]});
            }
        }

        return res;
    }
};