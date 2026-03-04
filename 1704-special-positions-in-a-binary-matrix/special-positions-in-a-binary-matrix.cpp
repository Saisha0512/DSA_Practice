class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> rows(n, 0), cols(m, 0);

        // Iterating over the whole matrix to mark the rows & cols with 1s : 
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                if (mat[i][j] == 1){
                    rows[i] ++;
                    cols[j] ++;
                }
            }
        }
        
        // Counting the special positions : 
        int cnt = 0;
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                if (mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1){
                    cnt ++;
                }
            }
        }

        return cnt;
    }
};