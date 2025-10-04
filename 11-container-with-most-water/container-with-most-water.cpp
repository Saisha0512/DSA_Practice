class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n - 1;
        int water = INT_MIN;
        while (i < j){
            water = max(water, (j - i)*min(height[j], height[i]));
            if (height[i] < height[j]){
                i ++;
            }
            else {
                j --;
            }
        }
        return water;
    }
};