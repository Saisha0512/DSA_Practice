class Solution {
    // find - path compression
    int find_parent(vector<int> &parent, int a){
        // base case
        if (parent[a] == a)     return a; // root account

        return parent[a] = find_parent(parent, parent[a]);
    }

    // union by rank
    void union_account(vector<int> &parent, vector<int> &rank, int a, int b){
        int s1 = find_parent(parent, a), s2 = find_parent(parent, b);
        if (s1 != s2){
            if (s1 > s2){
                rank[s1] += rank[s2];
                parent[s2] = s1;
            }
            else {
                rank[s2] += rank[s1];
                parent[s1] = s2;
            }
        }
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        vector<int> parent(n), rank(n, 0);
        for (int i = 0; i < n; i ++)    parent[i] = i;

        // merging the mails with the same accounts via union set operation
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i ++){
            for (int j = 1; j < accounts[i].size(); j ++){
                if (mp.find(accounts[i][j]) == mp.end()){
                    mp[accounts[i][j]] = i;
                }
                else {
                    union_account(parent, rank, i, mp[accounts[i][j]]);
                }
            }
        }

        // group emails under their root parent
        vector<vector<string>> group(n);
        for (auto &p : mp){
            int root = find_parent(parent, p.second);
            group[root].push_back(p.first);
        }

        // creating the final accounts
        vector<vector<string>> res;
        for (int i = 0; i < n; i ++){
            // all the emails of this account were moved to the root account
            if (group[i].empty()){
                continue;
            }

            // this is a root account
            // sorting the emails
            sort(group[i].begin(), group[i].end());
            // adding the owner's name
            group[i].insert(group[i].begin(), accounts[i][0]);
            res.push_back(group[i]);
        }

        return res;
    }
};