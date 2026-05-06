class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();

        // shifting the contents according to the gravity
        // vector<vector<char>> res;
        for (int row = 0; row < n; row ++){
            for (int j = box[row].size() - 1; j >= 0; j --){
                if (box[row][j] == '.' || box[row][j] == '*'){
                    continue;
                }
                else if (box[row][j] == '#'){
                    int idx = j;
                    for (int i = j + 1; i < box[row].size(); i ++){
                        if (box[row][i] == '.'){
                            idx = i;
                        }
                        else {
                            break;
                        }
                    }

                    box[row][j] = '.';
                    box[row][idx] = '#';
                }
            }
        }

        // rotating the box by 90
        vector<vector<char>> res(m, vector<char>(n));
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                res[j][n - i - 1] = box[i][j];
            }
        }

        return res;
    }
};