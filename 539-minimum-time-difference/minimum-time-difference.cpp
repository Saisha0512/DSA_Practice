class Solution {
public:
    int findMinDifference(vector<string>& time) {
        int n = time.size();
        vector<int> temp;

        for (auto &s : time){
            int hr = stoi(s.substr(0, 2));
            int min = stoi(s.substr(3, 2));
            int curr_time = hr * 60 + min;

            temp.push_back(curr_time);
        }

        // sorting this
        sort(temp.begin(), temp.end());

        int min_diff = INT_MAX;
        for (int i = 1; i < n; i ++){
            min_diff = min(min_diff, temp[i] - temp[i - 1]);
        }

        // checking circular difference
        min_diff = min(min_diff, 24*60 - temp[n - 1] + temp[0]);

        return min_diff;
    }
};