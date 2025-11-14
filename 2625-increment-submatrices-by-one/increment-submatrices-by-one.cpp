class Solution {
    void addOne(vector<vector<int>> &nums, int x1, int x2, int y1, int y2){
        // Iterating over the given submatrix : 
        for (int i = x1; i <= x2; i ++){
            for (int j = y1; j <= y2; j ++){
                nums[i][j] ++; // Adding 1
            }
        }
    }

public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        // Creating a matrix with all elements as 0 :
        vector<vector<int>> mat(n, vector<int>(n, 0)); 

        // Iterating for all the queries : 
        for (auto q : queries){
            addOne(mat, q[0], q[2], q[1], q[3]);
        }

        return mat;
    }
};