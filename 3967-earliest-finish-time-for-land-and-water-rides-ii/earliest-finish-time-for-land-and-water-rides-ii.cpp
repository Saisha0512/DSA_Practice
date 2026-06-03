class Solution {
public:
    int earliestFinishTime(vector<int>& landStart, vector<int>& landDur, vector<int>& waterStart, vector<int>& waterDur) {
        int n = landStart.size(), m = waterStart.size();

        // finding the land ride which can get finished the earliest
        int minlend = INT_MAX;
        for (int i = 0; i < n; i ++){
            minlend = min(minlend, landStart[i] + landDur[i]);
        }

        // checking if there is any water ride which can be finished just after the earliest land ride
        // also finding the water ride that can get finished the earlierst for the other way around
        int minwend = INT_MAX;
        int res = INT_MAX;
        for (int i = 0; i < m; i ++){
            minwend = min(minwend, waterStart[i] + waterDur[i]);
            res = min(res, max(minlend, waterStart[i]) + waterDur[i]);
        }

        // checking for the other way around - water ride first, land ride later
        for (int i = 0; i < n; i ++){
            res = min(res, max(minwend, landStart[i]) + landDur[i]);
        }

        return res;
    }
};