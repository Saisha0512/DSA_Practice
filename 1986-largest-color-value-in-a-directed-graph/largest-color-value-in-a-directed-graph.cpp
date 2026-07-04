class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> indegree(n, 0);
        vector<vector<int>> graph(n);
        vector<vector<int>> dp(n, vector<int>(26, 0));
        // dp[i][c] = max freq of c color nodes in any of the paths ending at the ith node

        for (auto &e : edges){
            graph[e[0]].push_back(e[1]);
            indegree[e[1]] ++;
        }

        queue<int> q;
        for (int i = 0; i < n; i ++){
            dp[i][colors[i] - 'a'] = 1;

            if (indegree[i] == 0){
                q.push(i);
            }
        }

        int visited = 0;
        int res = 1;
        // kahn's algo bfs loop
        while (!q.empty()){
            int curr = q.front();
            q.pop();
            visited ++;

            res = max(res, dp[curr][colors[curr] - 'a']);

            for (int nbr : graph[curr]){
                for (int c = 0; c < 26; c ++){
                    dp[nbr][c] = max(dp[nbr][c], dp[curr][c] + (c == (colors[nbr] - 'a')));
                }

                indegree[nbr] --;
                if (indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }

        return (visited == n)? res : -1;
    }
};