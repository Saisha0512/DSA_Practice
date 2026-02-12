class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int maxlen = 0;

        for (int i = 0; i < n; i ++){
            vector<int> freq(26, 0);
            int maxfreq = 0, dist = 0;

            for (int j = i; j < n; j ++){
                int idx = s[j] - 'a';
                if (freq[idx] == 0){
                    dist ++;
                }
                freq[idx] ++;
                maxfreq = max(maxfreq, freq[idx]);

                int currlen = j - i + 1;
                if (currlen == dist * maxfreq){
                    maxlen = max(maxlen, currlen);
                }
            }
        }

        return maxlen;
    }
};