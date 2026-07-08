class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int max_water = 0;

        while (l < r){
            max_water = max(max_water, min(height[l], height[r]) * (r - l));

            if (height[l] < height[r]){
                l ++;
            }
            else {
                r --;
            }
        }

        return max_water;
    }
};