class Solution {
public:
    string decodeCiphertext(string encoded, int rows) {
        int len = encoded.size();
        int n = rows, m = len / rows;

        // converting the string into grid
        vector<string> grid(n);
        for (int i = 0; i < n; i ++){
            grid[i] = encoded.substr(i * m, m);
        }

        // diagonally appending the characters in the resultant string
        string res = "";
        int i = 0, j = 0;
        while (i < n && j < m){
            int a = i, b = j;
            while (a < n && b < m){
                res.push_back(grid[a][b]);
                a ++;
                b ++;
            }

            j ++;
        }

        // removing trailing spaces
        while (!res.empty() && res.back() == ' '){
            res.pop_back();
        }

        return res;
    }
};