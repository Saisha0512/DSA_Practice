class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = capacity.size();
        sort(capacity.begin(), capacity.end());
        int sum = accumulate(apple.begin(), apple.end(), 0), cnt = 0;
        for (int i = n - 1; i >= 0 && sum > 0; i --){
            sum -= capacity[i];
            cnt ++;
        }

        return cnt;
    }
};