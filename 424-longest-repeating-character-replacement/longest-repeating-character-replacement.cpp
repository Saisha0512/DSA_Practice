class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char, int> freq;
        int start = 0, maxfreq = 0, maxlen = 0;

        for (int end = 0; end < n; end ++){
            freq[s[end]] ++;
            maxfreq = max(maxfreq, freq[s[end]]); // Updating the maximum frequency in the window 

            while ((end - start + 1) - maxfreq > k){
                freq[s[start]] --;
                start ++;
            }

            maxlen = max(maxlen, end - start + 1);
        }

        return maxlen;
    }
};