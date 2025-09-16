class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        set<int> letters;
        for (char ch : brokenLetters){
            letters.insert(ch);
        }

        int total = 0;
        bool flag = true;
        for (int i = 0; i < text.size(); i ++){
            if (text[i] == ' '){
                if (flag){
                    total ++;
                }
                flag = true;
            }
            else {
                if (letters.find(text[i]) != letters.end()){
                    flag = false;
                }
            }
        }
        if (flag){
            total ++;
        }
        return total;
    }
};