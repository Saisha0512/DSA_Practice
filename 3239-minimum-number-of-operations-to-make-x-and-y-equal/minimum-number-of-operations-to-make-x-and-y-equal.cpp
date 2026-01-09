class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        vector<int> dist(10001, -1);
        queue<int> q;

        q.push(x);
        dist[x] = 0;

        while (!q.empty()){
            int curr = q.front();
            q.pop();

            if (curr == y){
                return dist[curr];
            }

            // Operation 1 :
            if (curr % 11 == 0 && dist[curr / 11] == -1){
                dist[curr/11] = dist[curr] + 1;
                q.push(curr/11);
            }
            // Operation - 2 : 
            if (curr % 5 == 0 && dist[curr / 5] == -1){
                dist[curr/5] = dist[curr] + 1;
                q.push(curr/5);
            }
            // Operation - 3 : 
            if (curr - 1 >= 0 && dist[curr - 1] == -1){
                dist[curr - 1] = dist[curr] + 1;
                q.push(curr - 1);
            }
            // Operation - 4 : 
            if (curr + 1 <= 10000 && dist[curr + 1] == -1){
                dist[curr + 1] = dist[curr] + 1;
                q.push(curr + 1);
            }
        }

        return -1;
    }
};