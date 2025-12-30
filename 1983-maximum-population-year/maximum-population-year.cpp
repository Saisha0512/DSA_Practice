class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        // Constructing the difference array : 
        vector<long long> years(101, 0);
        for (auto &l : logs){
            int birth = l[0], death = l[1];
            years[birth - 1950] ++;
            years[death - 1950] --;
        }

        // Taking the prefix sum : 
        for (int i = 1; i < 101; i ++){
            years[i] += years[i - 1];
        }

        // Finding the minimum index with the maximum population : 
        int idx = 0;
        for (int i = 1; i < 101; i ++){
            if (years[i] > years[idx]){
                idx = i;
            }
        }

        return idx + 1950;
    }
};