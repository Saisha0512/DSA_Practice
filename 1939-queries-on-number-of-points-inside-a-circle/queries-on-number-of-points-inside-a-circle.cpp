class Solution {
    long double checkDistance(int x, int y, int a, int b){
        long double dist = (x - a)*(x - a) + (y - b)*(y - b);
        return sqrt(dist);
    }

public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> res;
        for (auto &q : queries){
            int x = q[0], y = q[1], r = q[2];
            int cnt = 0;
            for (auto &pt : points){
                int a = pt[0], b = pt[1];
                if (checkDistance(x, y, a, b) <= r){
                    cnt ++;
                }
            }

            res.push_back(cnt);
        }

        return res;
    }
};