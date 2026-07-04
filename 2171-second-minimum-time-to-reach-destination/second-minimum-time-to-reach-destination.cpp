class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> graph(n + 1);
        for (auto &e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        vector<int> first(n + 1, INT_MAX), second(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {min time, node}
        pq.push({0, 1});
        first[1] = 0;

        while (!pq.empty()){
            auto [curr_time, curr_node] = pq.top();
            pq.pop();

            if (curr_time > second[curr_node]){
                continue;
            }

            int temp_time = curr_time;
            if ((temp_time / change) % 2 == 1){ // red light on going
                temp_time += (change - (temp_time % change));
            }

            temp_time += time;
            for (int nbr : graph[curr_node]){
                if (temp_time < first[nbr]){
                    second[nbr] = first[nbr];
                    first[nbr] = temp_time;
                    pq.push({temp_time, nbr});
                }
                else if (temp_time > first[nbr] && temp_time < second[nbr]){
                    second[nbr] = temp_time;
                    pq.push({temp_time, nbr});
                }
            }
        }

        return second[n];
    }
};