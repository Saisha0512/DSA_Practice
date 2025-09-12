class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), l = 0, maxcnt = 0, maxlen = 0;
        map<char, int> freq;
        for (int r = 0; r < n; r ++){
            // Updating the frequency of the current character : 
            freq[s[r]] ++;
            maxcnt = max(maxcnt, freq[s[r]]);

            // Contracting the window while (window size - maxcnt) > k : 
            while ((r - l + 1) - maxcnt > k){
                freq[s[l]] --;
                l ++;
            }
            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};