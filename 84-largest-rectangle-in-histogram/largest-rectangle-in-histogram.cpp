class Solution {
    vector<int> pseFunction(vector<int> &heights){
        int n = heights.size();
        vector<int> pse(n);
        stack<int> s;

        for (int i = 0; i < n; i ++){
            while (!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }

            pse[i] = ((s.empty())? -1 : s.top());
            s.push(i);
        }

        return pse;
    }

    vector<int> nseFunction(vector<int> &heights){
        int n = heights.size();
        vector<int> nse(n);
        stack<int> s;

        for (int i = n - 1; i >= 0; i --){
            while (!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }

            nse[i] = ((s.empty())? n : s.top());
            s.push(i);
        }

        return nse;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse = pseFunction(heights), nse = nseFunction(heights);
        int maxarea = 0;

        for (int i = 0; i < n; i ++){
            int currarea = heights[i] * (nse[i] - pse[i] - 1);
            maxarea = max(maxarea, currarea);
        }

        return maxarea;
    }
};