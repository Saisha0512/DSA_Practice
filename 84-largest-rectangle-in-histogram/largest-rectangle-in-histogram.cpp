class Solution {
public:
    int largestRectangleArea(vector<int>& ht) {
        int n = ht.size();

        stack<int> s;
        vector<int> left(n), right(n);
        // left[i] = max area that can be covered starting from the index i extending towards left
        // right[i] = max area that cab be extended toward right starting from i

        // calculting the extendable area towards left with the height = ht[i]
        for (int i = 0; i < n; i ++){
            // popping all the greater elements
            while (!s.empty() && ht[s.top()] > ht[i]){
                s.pop();
            }

            // calculating the area
            if (s.empty()){
                left[i] = ht[i] * (i + 1);
            }
            else {
                left[i] = ht[i] * (i - s.top());
            }

            s.push(i);
        }

        // clearing the whole stack
        while (!s.empty()){
            s.pop();
        }

        // calculating the extendable area towards right with the height = ht[i]
        for (int i = n - 1; i >= 0; i --){
            // popping all the greater elements
            while (!s.empty() && ht[s.top()] >= ht[i]){
                s.pop();
            }

            // calculating the area
            if (s.empty()){
                right[i] = ht[i] * (n - i);
            }
            else {
                right[i] = ht[i] * (s.top() - i);
            }

            s.push(i);
        }

        // finding the max possible area with the ht[i]
        int maxarea = INT_MIN;
        for (int i = 0; i < n; i ++){
            maxarea = max(maxarea, left[i] + right[i] - ht[i]);
        }

        return maxarea;
    }
};