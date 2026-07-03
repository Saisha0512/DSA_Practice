class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto &e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        int min_len = INT_MAX;
        // starting bfs from every node
        for (int i = 0; i < n; i ++){
            vector<int> parent(n, -1), dist(n, -1);

            queue<int> q;
            q.push(i);
            dist[i] = 0;
            
            while (!q.empty()){
                int curr_node = q.front();
                q.pop();

                for (int nbr : graph[curr_node]){
                    if (dist[nbr] == -1){ // unvisited
                        dist[nbr] = dist[curr_node] + 1;
                        parent[nbr] = curr_node;
                        q.push(nbr);
                    }
                    // already visited node found - not parent
                    else if (parent[nbr] != curr_node && parent[curr_node] != nbr){
                        min_len = min(min_len, dist[curr_node] + dist[nbr] + 1);
                    }
                }
            }
        }

        return (min_len == INT_MAX)? -1 : min_len;
    }
};