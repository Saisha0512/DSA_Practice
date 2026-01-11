class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size();
        stack<int> s;
        int maxarea = 0;

        for (int i = 0; i < n; i ++){
            while (!s.empty() && heights[s.top()] >= heights[i]){
                int h = heights[s.top()];
                s.pop();
                int w = i - ((s.empty())? -1 : s.top()) - 1;
                maxarea = max(maxarea, h * w);
            }

            s.push(i);
        }

        return maxarea;
    }
};