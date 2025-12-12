class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        // Creating vectors to store (x, y) coordinates of the buildings : 
        unordered_map<int, vector<int>> x, y;

        for (auto &b : buildings){
            int p = b[0], q = b[1];

            x[p].push_back(q);
            y[q].push_back(p);
        }

        // Sorting all the vectors : 
        for (auto &p : x){
            sort(p.second.begin(), p.second.end());
        }
        for (auto &q : y){
            sort(q.second.begin(), q.second.end());
        }

        // Iterating over all the buildings & counting the number of safe buildings : 
        int cnt = 0;
        for (auto &building : buildings){
            int p = building[0], q = building[1];

            // Checking the horizontal order : 
            auto &hort = y[q];
            auto ith = lower_bound(hort.begin(), hort.end(), p);
            int idxh = ith - hort.begin();
            bool left = (idxh > 0);
            bool right = (idxh < hort.size() - 1);

            // Checking the vertical order : 
            auto &vert = x[p];
            auto itv = lower_bound(vert.begin(), vert.end(), q);
            int idxv = itv - vert.begin();
            bool down = (idxv > 0);
            bool up = (idxv < vert.size() - 1);

            // Checking all the conditions together : 
            if (left && right && down && up){
                cnt ++;
            }
        }

        return cnt;
    }
};