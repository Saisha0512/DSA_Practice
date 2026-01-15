class Solution {
    int countOne(int n){
        int cnt = 0;
        while (n){
            if (n & 1){
                cnt ++;
            }
            n = n >> 1;
        }
        return cnt;
    }

public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        for (int i = 0; i < n + 1; i ++){
            res[i] = countOne(i);
        }

        return res;
    }
};