class Solution {
public:
    int earliestFinishTime(vector<int>& landStart, vector<int>& landDuration, vector<int>& waterStart, vector<int>& waterDuration) {
        int n = landStart.size(), m = waterStart.size();

        // finding the land ride that ends the earliest
        int minlend = INT_MAX;
        for (int i = 0; i < n; i ++){
            minlend = min(minlend, landStart[i] + landDuration[i]);
        }

        // finding the water ride that can start after the earliest land ride ends
        int minwend = INT_MAX;
        int res = INT_MAX; // to store the possible result
        for (int i = 0; i < m; i ++){
            minwend = min(minwend, waterStart[i] + waterDuration[i]);
            res = min(res, max(minlend, waterStart[i]) + waterDuration[i]);
        }

        // checking again if we could take a water ride before a land ride
        for (int i = 0; i < n; i ++){
            res = min(res, max(minwend, landStart[i]) + landDuration[i]);
        }

        return res;
    }
};