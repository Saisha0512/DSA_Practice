class Solution {
public:
    int maxFreqSum(string s) {
        map<char, int> freq;
        int maxvow = 0, maxcons = 0;
        for (int i = 0; i < s.size(); i ++){
            freq[s[i]] ++;

            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                if (freq[s[i]] > maxvow){
                    maxvow = freq[s[i]];
                }
            }
            else {
                if (freq[s[i]] > maxcons){
                    maxcons = freq[s[i]];
                }
            }
        }
        return maxvow + maxcons;
    }
};