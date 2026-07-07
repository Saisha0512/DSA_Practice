class DSU {
    vector<int> parent, rank;

public : 
    DSU(int n){
        parent.resize(n, -1);
        rank.resize(n, 1);

        for (int i = 0; i < n; i ++){
            parent[i] = i;
        }
    }

    int find_parent(int x){
        if (parent[x] == x){
            return x;
        }

        return parent[x] = find_parent(parent[x]);
    }

    void union_set(int x, int y){
        int p1 = find_parent(x), p2 = find_parent(y);

        if (p1 != p2){
            if (rank[p1] > rank[p2]){
                rank[p1] += rank[p2];
                parent[p2] = p1;
            }
            else {
                rank[p2] += rank[p1];
                parent[p1] = p2;
            }
        }
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        DSU dsu(n * m);
        int cnt = 0;
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for (int x = 0; x < n; x ++){
            for (int y = 0; y < m; y ++){
                if (grid[x][y] == '0'){
                    continue;
                }

                int curr_node = x * m + y;
                cnt ++;

                for (auto &[dx, dy] : dir){
                    int i = x + dx, j = y + dy;

                    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0'){
                        continue;
                    }
                    int nbr = i * m + j;
                    if (dsu.find_parent(nbr) != dsu.find_parent(curr_node)){
                        dsu.union_set(nbr, curr_node);
                        cnt --;
                    }
                }
            }
        }

        return cnt;
    }
};