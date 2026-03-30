class Solution {
public:
    bool checkStrings(string s, string t) {
        vector<int> evens(26, 0), odds(26, 0), event(26, 0), oddt(26, 0);

        for (int i = 0; i < s.size(); i ++){
            if (i % 2 == 0){
                evens[s[i] - 'a'] ++;
                event[t[i] - 'a'] ++;
            }
            else {
                odds[s[i] - 'a'] ++;
                oddt[t[i] - 'a'] ++;
            }
        }

        for (int i = 0; i < 26; i ++){
            if (evens[i] != event[i] || odds[i] != oddt[i]){
                return false;
            }
        }

        return true;
    }
};