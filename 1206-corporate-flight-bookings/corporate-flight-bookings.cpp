class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0);
        
        // Iterating through the bookings : 
        for (auto &b : bookings){
            int first = b[0] - 1, last = b[1] - 1, seat = b[2];
            ans[first] += seat;
            if (last + 1 < n){
                ans[last + 1] -= seat;
            }
        }

        // Taking the prefix sum over the ans vector : 
        for (int i = 0; i < n; i ++){
            ans[i] += ((i > 0)? ans[i - 1] : 0);
        }

        return ans;
    }
};