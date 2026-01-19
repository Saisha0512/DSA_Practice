class Solution {
    bool isPossible(int len, vector<vector<int>> &pre, int threshold){
        int n = pre.size(), m = pre[0].size();

        for (int i = 0; i + len - 1 < n; i ++){
            for (int j = 0; j + len - 1 < m; j ++){
                int x = i + len - 1, y = j + len - 1;

                // Calculating the sum using 2D Prfix Sum : 
                int sum = pre[x][y];
                if (i > 0){
                    sum -= pre[i - 1][y];
                }
                if (j > 0){
                    sum -= pre[x][j - 1];
                }
                if (i > 0 && j > 0){
                    sum += pre[i - 1][j - 1];
                }

                // Checking with threshold : 
                if (sum <= threshold){
                    return true;
                }
            }
        }

        return false;
    }

public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
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

        // Applying Binary Search on the length : 
        int low = 1, high = min(n, m);
        int ans = 0;
        while (low <= high){
            int mid = (low + high)/2;

            if (isPossible(mid, pre, threshold)){
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};