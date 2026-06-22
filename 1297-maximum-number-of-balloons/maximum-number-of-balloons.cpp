class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26, 0);
        for (char ch : text){
            freq[ch - 'a'] ++;
        }

        int min_poss = INT_MAX;
        string res = "balon";
        for (char ch : res){
            if (ch == 'b' || ch == 'a' || ch == 'n'){
                min_poss = min(min_poss, freq[ch - 'a']);
            }
            else {
                min_poss = min(min_poss, freq[ch - 'a'] / 2);
            }
        }
        
        return min_poss;
    }
};