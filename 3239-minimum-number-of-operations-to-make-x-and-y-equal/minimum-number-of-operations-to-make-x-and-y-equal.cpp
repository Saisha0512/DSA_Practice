class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        // base case
        if (x <= y){
            return y - x;
        }

        vector<bool> vis(10001, false);
        queue<int> q;
        q.push(x);
        vis[x] = true;
        int steps = 0;

        while (!q.empty()){
            int size = q.size();

            while (size --){
                int curr = q.front();
                q.pop();

                if (curr == y){
                    return steps;
                }

                if (curr % 11 == 0){
                    int next = curr / 11;
                    if (!vis[next]){
                        q.push(next);
                        vis[next] = true;
                    }
                }
                if (curr % 5 == 0){
                    int next = curr / 5;
                    if (!vis[next]){
                        q.push(next);
                        vis[next] = true;
                    }
                }

                if (curr > 0 && !vis[curr - 1]){
                    q.push(curr - 1);
                    vis[curr - 1] == true;
                }
                if (curr + 1 <= 10000 && !vis[curr + 1]){
                    q.push(curr + 1);
                    vis[curr + 1] = true;
                }
            }

            steps ++;
        }

        return -1;
    }
};