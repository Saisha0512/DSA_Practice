class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();

        int res = 0;
        int cntb = 0;
        for (char ch : s){
            // Encountered a
            if (ch == 'b'){
                cntb ++;
            }
            else {
                if (cntb){
                    res ++;
                    cntb --;
                }
            }
        }

        return res;
    }
};