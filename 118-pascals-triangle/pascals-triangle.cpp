class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> pascal;

        for (int i = 0; i < n; i ++){
            vector<int> curr;

            for (int j = 0; j < i + 1; j ++){
                if (j == 0 || j == i){
                    curr.push_back(1);
                }
                else {
                    int temp = pascal[i - 1][j - 1] + pascal[i - 1][j];
                    curr.push_back(temp);
                }
            }

            pascal.push_back(curr);
        }

        return pascal;

        // TC : O(n * n)
        // SC : O(n * n)
    }
};