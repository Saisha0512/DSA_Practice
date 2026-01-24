class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> pascal;

        for (int i = 0; i < n; i ++){
            vector<int> temp;

            for (int j = 0; j < i + 1; j ++){
                if (j == 0 || j == i){
                    temp.push_back(1);
                }
                else {
                    int curr = pascal[i - 1][j] + pascal[i - 1][j - 1];
                    temp.push_back(curr);
                }
            }

            pascal.push_back(temp);
        }

        return pascal;
    }
};