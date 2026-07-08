class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int max_len = 0;
        unordered_map<char, int> freq;

        int l = 0;
        for (int r = 0; r < n; r ++){
            // expanding the window
            freq[s[r]] ++;

            // contracting the window
            while (freq[s[r]] > 1){
                freq[s[l]] --;
                l ++;
            }

            max_len = max(max_len, r - l + 1);
        }

        return max_len;
    }
};