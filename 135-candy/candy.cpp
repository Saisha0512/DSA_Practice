class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);

        // Checking from left to right : 
        for (int i = 1; i < n; i ++){
            if (ratings[i] > ratings[i - 1]){
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Checking from right to left : 
        for (int i = n - 2; i >= 0; i --){
            if (ratings[i] > ratings[i + 1]){
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        // Calculating the total number of candies : 
        int total = 0;
        for (auto num : candies)    total += num;

        return total;
    }
};