class Solution {
public:
    int minPartitions(string n) {
        int cnt = 0;
        for (char ch : n){
            int x = ch - '0';
            cnt = max(cnt, x);
        }

        return cnt;
    }
};