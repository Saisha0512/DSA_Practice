class Solution {
    static bool compare(vector<int> &a, vector<int> &b){
        if (a[0] == b[0]){
            return a[1] > b[1];
        }

        return a[0] < b[0];
    }

public:
    int numberOfWeakCharacters(vector<vector<int>>& prop) {
        int n = prop.size();

        int cnt = 0;
        sort(prop.begin(), prop.end(), compare);
        stack<pair<int, int>> s;
        for (int i = 0; i < n; i ++){
            // popping all the elements less than the current pair
            while (!s.empty() && s.top().first < prop[i][0] && s.top().second < prop[i][1]){
                cnt ++;
                s.pop();
            }

            s.push({prop[i][0], prop[i][1]});
        }

        return cnt;
    }
};