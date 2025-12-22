// DSU Class Implementation : 
class DSU {
    vector<int> parent;
    vector<int> rank;

public : 
    DSU (int v){
        // Assigning the sizes to the vectors : 
        parent.resize(v + 1, -1);
        rank.resize(v + 1, 1);
        for (int i = 1; i <= v; i ++){
            parent[i] = i;
        }
    }

    int find(int x){
        // Base Condition : 
        if (parent[x] == x){
            return x;
        }

        // Checking the parent : 
        return parent[x] = find(parent[x]);
    }

    void unionSet(int x, int y){
        int s1 = find(x);
        int s2 = find(y);
        // Union by Rank : 
        if (s1 != s2){
            if (rank[s1] >= rank[s2]){
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
            else {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU d(n);

        // Iterating over all the edges : 
        for (auto &edge : edges){
            int a = edge[0], b = edge[1];
            int s1 = d.find(a);
            int s2 = d.find(b);
            // If the current edges forms a cycle, then we need to remove it : 
            if (s1 == s2){
                return {a, b};
            }
            else {
                d.unionSet(a, b); // Otherwise, adding the edge
            }
        }

        return {-1, -1};
    }
};