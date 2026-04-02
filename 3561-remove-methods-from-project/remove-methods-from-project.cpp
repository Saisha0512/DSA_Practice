class Solution {
    void dfs(int node, vector<vector<int>> &out, vector<bool> &vis){
        vis[node] = true;

        for (auto nbr : out[node]){
            if (!vis[nbr]){
                dfs(nbr, out, vis);
            }
        }
    }

public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invo) {
        // Constructing a in & out vectors : 
        vector<vector<int>> in(n), out(n);
        for (auto &e : invo){
            int a = e[0], b = e[1];

            out[a].push_back(b);
            in[b].push_back(a);
        }

        // Marking all the suspicious nodes : 
        vector<bool> sus(n, false);
        dfs(k, out, sus);

        // Checking if removal of that suspicious node is valid : 
        for (int i = 0; i < n; i ++){
            if (sus[i]){
                for (auto &nbr : in[i]){
                    // Any one method is invoked from outside the group, so none can be removed : 
                    if (!sus[nbr]){
                        vector<int> ans;
                        for (int j = 0; j < n; j ++){
                            ans.push_back(j);
                        }
                        return ans;
                    }
                }
            }
        }

        // Returning the remaining nodes : 
        vector<int> ans;
        for (int i = 0; i < n; i ++){
            if (!sus[i]){
                ans.push_back(i);
            }
        }

        return ans;
    }
};