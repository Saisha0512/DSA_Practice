class Solution {
public:
    int trap(vector<int>& ht) {
        int n = ht.size();

        vector<int> left(n), right(n);
        // calculating left prefix max
        left[0] = ht[0];
        for (int i = 1; i < n; i ++){
            left[i] = max(left[i - 1], ht[i]);
        }
        // calculating right prefix max
        right[n - 1] = ht[n - 1];
        for (int i = n - 2; i >= 0; i --){
            right[i] = max(right[i + 1], ht[i]);
        }

        // calculating the water for every bar
        int total = 0;
        for (int i = 0; i < n; i ++){
            total += (min(left[i], right[i]) - ht[i]);
            // water in the current bar will be filled up till the minimum height of the maximum bar on both left & right sides
        }

        return total;
    }
};