class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int water = INT_MIN;

        while (l < r){
            water = max(water, min(height[l], height[r])*(r - l));
        
            if (height[l] < height[r]){
                l ++;
            }
            else {
                r --;
            }
        }

        return water;
    }
};