class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        // counting the frequency of each character
        vector<int> freq(26, 0);
        for (char ch : s){
            freq[ch - 'a'] ++;
        }

        // used characters
        vector<int> used(26, 0);
        int i = 0;
        // keeping prefix equal to target for as long as possible
        while (i < n){
            int ch = target[i] - 'a';

            if (used[ch] == freq[ch]){
                break;
            }

            used[ch] ++;
            i ++;
        }

        // trying to make the string larger, changing the latest possible position first to preserve the longest equal prefix
        while (i >= 0){
            if (i < n){
                int curr = target[i] - 'a';

                // choosing the smallest available character greater than target[i]
                for (int j = curr + 1; j < 26; j ++){
                    if (used[j] == freq[j]){
                        continue;
                    }

                    string res = target.substr(0, i);
                    res += char('a' + j);

                    // completing the suffix with the smallest ordering
                    for (int ch = 0; ch < 26; ch ++){
                        int rem = freq[ch] - used[ch];

                        if (ch == j){
                            rem --;
                        }

                        res += string(rem, char('a' + ch));
                    }

                    return res;
                }
            }

            // if the current position cannot be increased, then remove the previous target character before moving one position left
            if (i > 0){
                used[target[i - 1] - 'a'] --;
            }

            i --;
        }

        return "";
    }
};