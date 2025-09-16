class Solution {
public:
    int scoreHelper(vector<string> &words, vector<int> &score, vector<int> &lettercnt, int i){
        // Base Case : 
        if (i == words.size()){
            return 0;
        }

        // Recursive Case : 
        int maxsc = 0;
        // CASE 1 : Not considering the current word : 
        maxsc = scoreHelper(words, score, lettercnt, i + 1);

        // CASE 2 : Considering the current word : 
        int currsc = 0;
        vector<int> wordcnt(26, 0);
        for (char &ch : words[i]){
            wordcnt[ch - 'a'] ++;
            currsc += score[ch - 'a'];
        }

        bool valid = true;
        for (int i = 0; i < 26; i ++){
            if (lettercnt[i] >= wordcnt[i]){
                continue;
            }
            else {
                valid = false;
                break;
            }
        }

        if (valid){
            for (int i = 0; i < 26; i ++){
                lettercnt[i] -= wordcnt[i];
            }

            maxsc = max(maxsc, currsc + scoreHelper(words, score, lettercnt, i + 1));

            for (int i = 0; i < 26; i ++){
                lettercnt[i] += wordcnt[i];
            }
        }

        return maxsc;
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> lettercnt(26, 0);
        for (char &ch : letters){
            lettercnt[ch - 'a'] ++;
        }

        return scoreHelper(words, score, lettercnt, 0);
    }
};