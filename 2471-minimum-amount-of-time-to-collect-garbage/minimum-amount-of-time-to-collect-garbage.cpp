class Solution {
    int getCount(string &s, char ch){
        int cnt = 0;
        for (char x : s){
            if (x == ch){
                cnt ++;
            }
        }
        return cnt;
    }

public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size(); // No. of houses

        vector<int> m(n, 0), g(n, 0), p(n, 0); // Vectors to store the M, P & G frequencies for each house
        // Entering all the values : 
        int maxm = INT_MIN, maxp = INT_MIN, maxg = INT_MIN;
        for (int i = 0; i < n; i ++){
            m[i] = getCount(garbage[i], 'M');
            p[i] = getCount(garbage[i], 'P');
            g[i] = getCount(garbage[i], 'G');
            
            if (m[i]){
                maxm = max(maxm, i);
            }
            if (p[i]){
                maxp = max(maxp, i);
            }
            if (g[i]){
                maxg = max(maxg, i);
            }
        }

        // For all the trucks : 
        int total = 0;
        for (int i = 0; i < n; i ++){
            total += m[i] + p[i] + g[i];

            if (i + 1 <= maxm){
                total += travel[i];
            }
            if (i + 1 <= maxp){
                total += travel[i];
            }
            if (i + 1 <= maxg){
                total += travel[i];
            }
        }

        return total;
    }
};