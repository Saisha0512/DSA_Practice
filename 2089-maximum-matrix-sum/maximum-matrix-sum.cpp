class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int neg = 0, minabs = INT_MAX;
        long long sum = 0;

        for (int i = 0; i < n; i ++){
            for (int j = 0; j < n; j ++){
                if (matrix[i][j] < 0) {
                    neg ++;
                }

                sum += abs(matrix[i][j]);
                minabs = min(minabs, abs(matrix[i][j]));
            }
        }

        if (neg % 2 == 0){
            return sum;
        }

        return sum - (long long)(2 * minabs);
    }
};