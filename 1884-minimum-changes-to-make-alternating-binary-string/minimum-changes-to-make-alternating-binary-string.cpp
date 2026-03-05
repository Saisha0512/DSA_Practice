class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < n; i ++){
            char exp0 = ((i % 2 == 0)? '0' : '1');
            char exp1 = ((i % 2 == 0)? '1' : '0');

            if (s[i] != exp0){
                cnt0 ++;
            }
            if (s[i] != exp1){
                cnt1 ++;
            }
        }

        return min(cnt0, cnt1);
    }
};