class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();

        vector<vector<int>> pre(n, vector<int>(m, 0));
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                pre[i][j] = mat[i][j];

                if (i > 0){
                    pre[i][j] += pre[i - 1][j];
                }
                if (j > 0){
                    pre[i][j] += pre[i][j - 1];
                }
                if (i > 0 && j > 0){
                    pre[i][j] -= pre[i - 1][j - 1];
                }
            }
        }

        // Caculating the answer vector : 
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                int a = ((i - k >= 0)? i - k : 0), b = ((j - k >= 0)? j - k : 0);
                int c = ((i + k < n)? i + k : n - 1), d = ((j + k < m)? j + k : m - 1);

                ans[i][j] = pre[c][d];
                if (a > 0){
                    ans[i][j] -= pre[a - 1][d];
                }
                if (b > 0){
                    ans[i][j] -= pre[c][b - 1];
                }
                if (a > 0 && b > 0){
                    ans[i][j] += pre[a - 1][b - 1];
                }
            }
        }

        return ans;
    }
};