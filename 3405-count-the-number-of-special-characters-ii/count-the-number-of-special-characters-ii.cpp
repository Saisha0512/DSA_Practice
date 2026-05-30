class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<int> lastlower(26, -1), firstupper(26, -1);

        for (int i = 0; i < n; i ++){
            char ch = word[i];

            // storing the last occurence of every lower character
            if (ch >= 'a' && ch <= 'z'){
                lastlower[ch - 'a'] = i;
            }

            // storing the first occurrence of every upper character
            if (ch >= 'A' && ch <= 'Z' && firstupper[ch - 'A'] == -1){
                firstupper[ch - 'A'] = i;
            }
        }

        // checking the validity of each character
        int cnt = 0;
        for (int i = 0; i < 26; i ++){
            if (lastlower[i] != -1 && firstupper[i] != -1 && lastlower[i] < firstupper[i]){
                cnt ++;
            }
        }

        return cnt;
    }
};