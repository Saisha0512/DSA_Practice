class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> lmax(n), rmax(n);
        // Calculating the left max for each index : 
        lmax[0] = height[0];
        for (int i = 1; i < n; i ++){
            lmax[i] = max(lmax[i - 1], height[i]);
        }

        // Calculating the right max for each index : 
        rmax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i --){
            rmax[i] = max(rmax[i + 1], height[i]);
        }

        // Iterating over all the indexes to calculate the trapped water : 
        int water = 0;
        for (int i = 0; i < n; i ++){
            water += min(lmax[i], rmax[i]) - height[i];
        }

        return water;
    }
};