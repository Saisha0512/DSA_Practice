class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groups) {
        int n = groups.size();
        unordered_map<int, vector<int>> m; // {size, group members}
        vector<vector<int>> res;

        for (int i = 0; i < n; i ++){
            int size = groups[i];
            m[size].push_back(i);

            if (m[size].size() == size){
                res.push_back(m[size]);
                m[size].clear();
            }
        }

        return res;
    }
};