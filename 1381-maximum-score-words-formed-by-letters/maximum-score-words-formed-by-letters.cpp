class Solution {
public:

    void scoreHelper(vector<string> &words, unordered_map<char, int> freq, vector<int> &score, int i, int currsc, int &maxsc){
        // Base Case : 
        if (i == words.size()){
            maxsc = max(maxsc, currsc);
            return;
        }

        // Recursive Case : 
        // Case 1 : Not considering the current word : 
        scoreHelper(words, freq, score, i + 1, currsc, maxsc);

        // Case 2 : Not considering the current word : 
        bool flag = true;
        int temp = 0;
        for (char &ch : words[i]){
            if (freq[ch] > 0){
                temp += score[ch - 'a'];
                freq[ch] --;
            }
            else {
                flag = false;
                break;
            }
        }

        // If all the letters in current word have the required frequency, then we add its total score in currsc : 
        if (flag){
            currsc += temp;
        }

        // Moving to the next word : 
        scoreHelper(words, freq, score, i + 1, currsc, maxsc);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char, int> freq;
        for (int i = 0; i < letters.size(); i ++){
            freq[letters[i]] ++;
        }

        int maxsc = 0;
        scoreHelper(words, freq, score, 0, 0, maxsc);
        return maxsc;
    }
};