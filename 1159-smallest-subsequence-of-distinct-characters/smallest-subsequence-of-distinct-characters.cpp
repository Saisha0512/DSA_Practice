class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        
        // counting the freq of char
        vector<int> freq(26, 0);
        vector<bool> vis(26, false);
        for (char ch : s){
            freq[ch - 'a'] ++;
        }

        string res = "";
        for (char ch : s){
            freq[ch - 'a'] --; // adding one occurrence of this character to the string
            if (vis[ch - 'a']){
                continue; // character is already present in the string
            }

            // popping the character from the stack if
            while (!res.empty() && res.back() > ch && freq[res.back() - 'a'] > 0){
                vis[res.back() - 'a'] = false;
                res.pop_back();
            }

            res.push_back(ch);
            vis[ch - 'a'] = true;
        }

        return res;
    }
};