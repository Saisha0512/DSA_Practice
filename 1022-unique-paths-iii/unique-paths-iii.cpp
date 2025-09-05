class Solution {
public:
    void takingSteps(vector<vector<int>> &grid, int i, int j, int &cnt, int empty){
        // Base Case : 
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1){
            return;
        }
        if (grid[i][j] == 2){
            if(empty == 0){
                cnt ++;
            }
            return;
        }

        int temp = grid[i][j];
        grid[i][j] = -1;

        // Recursive Case : 
        takingSteps(grid, i + 1, j, cnt, empty - 1);
        takingSteps(grid, i - 1, j, cnt, empty - 1);
        takingSteps(grid, i, j + 1, cnt, empty - 1);
        takingSteps(grid, i, j - 1, cnt, empty - 1);

        // Backtrack : 
        grid[i][j] = temp;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int a = -1, b = -1, empty = 0;
        for (int i = 0; i < grid.size(); i ++){
            for (int j = 0; j < grid[i].size(); j ++){
                if (grid[i][j] == 0){
                    empty ++;
                }
                else if (grid[i][j] == 1){
                    a = i;
                    b = j;
                    empty ++;
                }
            }
        }

        int cnt = 0;
        takingSteps(grid, a, b, cnt, empty);
        return cnt;
    }
};