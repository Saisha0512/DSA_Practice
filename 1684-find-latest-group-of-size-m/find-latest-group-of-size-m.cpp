class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        int res = -1, cnt = 0;

        vector<int> len(n + 2, 0);
        for (int step = 0; step < n; step ++){
            int i = arr[step];

            int left = len[i - 1], right = len[i + 1];
            int total = left + right + 1;
            len[i - left] = total;
            len[i + right] = total;
            len[i] = total;

            if (m == left){
                cnt --;
            }
            if (m == right){
                cnt --;
            }
            if (total == m){
                cnt ++;
            }

            if (cnt > 0){
                res = step + 1;
            }
        }

        return res;
    }
};