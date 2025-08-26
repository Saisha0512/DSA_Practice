class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dim) {
        int maxarea = INT_MIN; 
        float maxdiag = INT_MIN;
        for (int i = 0; i < dim.size(); i ++){
            int l = dim[i][0], b = dim[i][1];
            int area = l*b;
            float diag = sqrt(l*l + b*b);
            if (diag > maxdiag){
                maxarea = area;
                maxdiag = diag;
            }
            else if (diag == maxdiag){
                maxarea = max(maxarea, area);
            }
        }
        return maxarea;
    }
};