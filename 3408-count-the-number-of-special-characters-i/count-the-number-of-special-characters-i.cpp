class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lower(26, 0), upper(26, 0);

        // counting the frequency of every character in both upper & lower cases
        for (char ch : word){
            // lower case
            if (ch >= 'a' && ch <= 'z'){
                lower[ch - 'a'] ++;
            }

            // upper case
            if (ch >= 'A' && ch <= 'Z'){
                upper[ch - 'A'] ++;
            }
        }

        // counting the no of special letters present
        int cnt = 0;
        for (int i = 0; i < 26; i ++){
            if (upper[i] && lower[i]){
                cnt ++;
            }
        }

        return cnt;
    }
};