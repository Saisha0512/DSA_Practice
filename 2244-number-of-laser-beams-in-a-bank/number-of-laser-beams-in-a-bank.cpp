class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size(), m = bank[0].size();

        int last = 0;
        // First row : 
        for (char ch : bank[0]){
            if (ch == '1'){
                last ++;
            }
        }

        // Other rows : 
        int cnt = 0;
        for (int i = 1; i < n; i ++){
            int curr = 0;
            for (char ch : bank[i]){
                if (ch == '1'){
                    curr ++;
                }
            }

            cnt += (curr * last);
            if (curr != 0){
                last = curr;
            }
        }

        return cnt;
    }
};